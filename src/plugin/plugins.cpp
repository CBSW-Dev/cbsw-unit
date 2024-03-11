#include "pch.hpp"
#include "plugins.hpp"

#include "utility/unused.hpp"

namespace CBSW::Unit {
    class PluginChainFinal: public PluginNextHandler {
    public:
        PluginChainFinal(PluginFinal& final):
            _final(final)
        {}

        int next(Arguments& arguments) noexcept {
            unused(arguments);
            return _final.finalPluginFunction();
        }
    private:
        PluginFinal& _final;
    };

    class PluginChainWrapper: public PluginNextHandler {
    public:
        PluginChainWrapper(Plugin& plugin, PluginNextHandler& next):
            _plugin(plugin),
            _next(next)
        {}

        int next(Arguments& arguments) noexcept {
            return _plugin.initialise(arguments, _next);
        }
    private:
        Plugin &_plugin;
        PluginNextHandler& _next;
    };

    int Plugins::run(Arguments& arguments, PluginFinal& final) {
        std::list<PluginNextHandler*> nextHandlers;

        PluginChainFinal* finalChain = new PluginChainFinal(final);
        PluginNextHandler* next = finalChain;
        nextHandlers.push_back(finalChain);

        //construct in reverse order

        for (auto plugin: _plugins) {
            PluginNextHandler* nextHandler = new PluginChainWrapper(*plugin, *next);
            next = nextHandler;
            nextHandlers.push_back(nextHandler);
        }

        //now next contains the first plugin in the chain
        int output = next->next(arguments);

        for (PluginNextHandler* handler: nextHandlers) {
            delete handler;
        }
        return output;
    }

    void Plugins::registerPlugin(Plugin& plugin) {
        _plugins.push_back(&plugin);
    }
}
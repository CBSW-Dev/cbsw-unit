#include "pch.hpp"
#include "plugins.hpp"

namespace CBSW::Unit {
    class PluginChainFinal: public PluginNextHandler {
    public:
        PluginChainFinal(PluginFinalFunction final):
            _final(final)
        {}

        int next(int argc, char** argv) noexcept {
            return _final(argc, argv);
        }
    private:
        PluginFinalFunction _final;
    };

    class PluginChainWrapper: public PluginNextHandler {
    public:
        PluginChainWrapper(Plugin& plugin, PluginNextHandler& next):
            _plugin(plugin),
            _next(next)
        {}

        int next(int argc, char** argv) noexcept {
            return _plugin.initialise(argc, argv, _next);
        }
    private:
        Plugin &_plugin;
        PluginNextHandler& _next;
    };

    int Plugins::run(int argc, char** argv, PluginFinalFunction final) {
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
        int output = next->next(argc, argv);

        for (PluginNextHandler* handler: nextHandlers) {
            delete handler;
        }
        return output;
    }
}

CBSW::Unit::Plugins& cbsw_unit_plugins() noexcept {
    static CBSW::Unit::Plugins plugins;
    return plugins;
}
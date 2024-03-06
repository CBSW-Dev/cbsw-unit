#pragma once

#include "deferred-reporter-action.hpp"

#include <list>

namespace CBSW::Unit {
    class DeferredReporterActionList {
    public:
        DeferredReporterActionList() = default;

        DeferredReporterActionList(const DeferredReporterActionList& list);
        DeferredReporterActionList(DeferredReporterActionList&& list);

        ~DeferredReporterActionList();

        DeferredReporterActionList& operator=(const DeferredReporterActionList& list);
        DeferredReporterActionList& operator=(DeferredReporterActionList&& list);

        using List = std::list<DeferredReporterAction*>;
        using Iterator = List::iterator;

        Iterator begin();
        Iterator end();
        void push_back(DeferredReporterAction* action);
        void clear();
    private:
        List _list;
    };
}
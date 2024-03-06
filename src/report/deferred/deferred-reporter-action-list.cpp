#include "pch.hpp"
#include "deferred-reporter-action-list.hpp"


namespace CBSW::Unit {
    DeferredReporterActionList::DeferredReporterActionList(const DeferredReporterActionList& list) {
        for (DeferredReporterAction* action: list._list) {
            _list.push_back(action->clone());
        }
    }

    DeferredReporterActionList::DeferredReporterActionList(DeferredReporterActionList&& list):
        _list(std::move(list._list))
    {
        list._list = List();
    }

    DeferredReporterActionList& DeferredReporterActionList::operator=(const DeferredReporterActionList& list) {
        if (this == &list) {
            return *this;
        }
        for (DeferredReporterAction* action: _list) {
            delete action;
        }
        _list.clear();

        for (DeferredReporterAction* action: list._list) {
            _list.push_back(action->clone());
        }
        return *this;
    }

    DeferredReporterActionList& DeferredReporterActionList::operator=(DeferredReporterActionList&& list) {
        if (this == &list) {
            return *this;
        }
        for (DeferredReporterAction* action: _list) {
            delete action;
        }
        _list = std::move(list._list);
        list._list = List();

        return *this;
    }

    DeferredReporterActionList::~DeferredReporterActionList() {
        for (DeferredReporterAction* action: _list) {
            delete action;
        }
    }

    DeferredReporterActionList::Iterator DeferredReporterActionList::begin() {
        return _list.begin();
    }

    DeferredReporterActionList::Iterator DeferredReporterActionList::end() {
        return _list.end();
    }

    void DeferredReporterActionList::push_back(DeferredReporterAction* action) {
        _list.push_back(action);
    }

    void DeferredReporterActionList::clear() {
        for (DeferredReporterAction* action: _list) {
            delete action;
        }
        _list.clear();
    }
}
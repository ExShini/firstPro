#include "module.h"

module::module()
{
    externalLevel = new map<int,GObject*>();
    middleLevel = map<int,GObject*>();
    topLevel = map<int,GObject*>();
}

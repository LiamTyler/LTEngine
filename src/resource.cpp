#include "include/resource.h"

Resource::Resource() : Resource(-1) {
}

Resource::Resource(RID r) {
    rid = r;
}

Resource::~Resource() {
}

#ifndef INCLUDE_RESOURCE_H_
#define INCLUDE_RESOURCE_H_

#include "include/rid.h"

class Resource {
    public:
        Resource();
        Resource(RID r);
        virtual ~Resource();

        Resource& operator=(const Resource& r) {}
        Resource(const Resource& r) {}

        RID rid;
};

#endif  // INCLUDE_RESOURCE_H_

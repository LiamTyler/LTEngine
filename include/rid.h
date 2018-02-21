#ifndef INCLUDE_RID_H_
#define INCLUDE_RID_H_

#include <stddef.h>
#include <iostream>

class RID {
    public:
        RID() { id_ = 0; }
        RID(unsigned int r) { id_ = r; }
        unsigned int GetID() const { return id_; }

        bool operator==(const RID& r) const {
            return id_ == r.id_;
        }
        bool operator!=(const RID& r) const {
            return !(*this == r);
        }

        friend std::ostream& operator<<(std::ostream& out, const RID& r) {
            return out << r.id_;
        }

    private:
        unsigned int id_;
};

namespace std {
    template<> struct hash<RID> {
        size_t operator()(const RID& r) const {
            return hash<unsigned int>()(r.GetID());
        }
    };
}

#endif  // INCLUDE_RID_H_

#ifndef LC_ID_MAP_H
#define LC_ID_MAP_H

#include <bitset>

template<size_t range>
class IDMap {
  public:
    IDMap(void) : counter_(0) {}

    bool Next(size_t& next_id);

    void Free(size_t id);
  private:
    typedef std::bitset<range> IDBitmap;
    size_t counter_;
    IDBitmap id_bitmap_;
};

template<size_t range>
bool IDMap<range>::Next(size_t& next_id) {
    if (id_bitmap_.count() == id_bitmap_.size())
        return false;
    next_id = counter_;
    do {
        if (!id_bitmap_.test(next_id)) {
            id_bitmap_.set(next_id);
            counter_ = (next_id + 1) % range;
            return true;
        }
        next_id = (next_id + 1) % range;
    } while (next_id != counter_);
    return false;
}

template<size_t range>
void IDMap<range>::Free(size_t id) {
    if (id < range)
        id_bitmap_.reset(id);
}

#endif // LC_ID_MAP_H


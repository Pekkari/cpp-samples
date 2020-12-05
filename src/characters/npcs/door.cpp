#include "characters/npcs/door.hpp"


/*

    Returns true if door IS locked, otherwise false.

*/
bool Door::isLocked() const {

    return isLocked_;
}

/*

    Return true if open succeed (door was locked), and
    false if open did not succeed (door already open).

*/
bool Door::open() {


    if(isLocked())
    {
        isLocked_ = false;
        return true;
    }
    else
    {
        return false;
    }

}

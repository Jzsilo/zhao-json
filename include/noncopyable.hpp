//
// Created by zhao on 24-05-01.
//

#pragma once

namespace zhao {

namespace json {

class noncopyable {
public:
    noncopyable(const noncopyable&) = delete;
    void operator=(const noncopyable&) = delete;
protected:
    noncopyable() = default;
    ~noncopyable() = default;
};

} // namespace json

} // namespace zhao

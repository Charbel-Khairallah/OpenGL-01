#include <uuid.h>

#include <random>
#include <mutex>


#include "UUID.h"


std::string UUID::NewUUID()
{
    static std::mt19937 engine(std::random_device{}());

    static uuids::uuid_random_generator generator(engine);

    static std::mutex mutex;

    std::lock_guard<std::mutex> lock(mutex);

    return uuids::to_string(generator());
}
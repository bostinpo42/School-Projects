
#ifndef BUCKET_H
#define BUCKET_H

#define DEFAULT_SIZE 157
#define SCALING_FACTOR 2
#define RESIZE_COND 0.6
#define MAX_PROBE_ATT 27

enum bucketStatus{Empty = 0, Available = 1, Occupied = 2};

template<typename T>
struct Bucket{
    Bucket() : status{Empty} {}

    T item;
    int status;
};

#endif
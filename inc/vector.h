#pragma once

#include "../std/std.h"

typedef struct vector {
    int length, capacity;
    void** buffer;
} vector;

typedef void (*vectorDtor)(void*); ///For use with vectorFreeObjs
typedef void* (*vectorMapper)(void*); ///For use with vectorMap

/**
 * Initialize a vector and return it.
 */
vector* vectorInit (vector* v, int initialCapacity);

/**
 * Cleans up resources allocated by the vector but not the vector itself.
 */
void vectorFree (vector* v);

/**
 * As with vectorFree, but also call a given destructor on each contained element
 * @see vectorDtor
 */
void vectorFreeObjs (vector* v, void (*dtor)(void*));

void vectorPush (vector* v, void* item);

/**
 * Add to the end of a vector from an array.
 *
 * initialCapacity must be greater than length.
 * Won't modify array.
 */
vector* vectorPushFromArray (vector* v, void** array, int length);

void* vectorPop (vector* v);

/**
 * Returns the value, or null if out of bounds.
 */
void* vectorGet (const vector* v, int n);

/**
 * Attempts to set an index to a value. Returns whether it failed.
 */
bool vectorSet (vector* v, int n, void* value);

/**
 * Maps dest[n] to f(src[n]) for n in min(dest->length, src->length).
 *
 * src and dest can match.
 * @see vectorMapper
 */
void vectorMap (vector* dest, void* (*f)(void*), vector* src);

#ifndef BVHNODEH
#define BVHNODEH

#include <iostream>
#include <stdlib.h>
#include "aabb.h"
#include "hitable.h"

class bvh_node:public hitable
{
public:
    bvh_node(){}
    ~bvh_node() {free();}
    virtual void free();  
    bvh_node(hitable **l, int n, float time0=0, float time1=0);
    virtual bool hit(const ray&r, float tmin, float tmax, hit_record& rec) const;
    virtual bool bounding_box(float t0, float t1, aabb& b) const;
    hitable *left;
    hitable *right;
    aabb box;

};

int box_x_compare(const void *a, const void *b);

int box_y_compare(const void *a, const void *b);

int box_z_compare(const void *a, const void *b);


#endif

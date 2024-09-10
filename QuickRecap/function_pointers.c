#include <stdio.h>

// Define a structure called GeoObject
struct GeoObject {
    int id;
};

// Define a function that matches the signature
void draw(struct GeoObject obj) {
    printf("Drawing GeoObject with ID: %d\n", obj.id);
}

int main() {

    typedef void(*DrawFunc) (struct GeoObject);

    // Use DrawFunc to declare a function pointer
    DrawFunc myDrawFunction = draw;

    // Create an instance of GeoObject
    struct GeoObject obj = {42};

    // Call the function via the function pointer
    myDrawFunction(obj);
    (*myDrawFunction)(obj);

    //printf(myDrawFunction);

    return 0;
}

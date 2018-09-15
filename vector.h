#ifndef VECTOR_H
#define VECTOR_H



template <typename Tr>
class Vector {
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
             
    private:
        T* data;
        int dataSize;

        int dimensions;
        int* dimensionSizes;
        Operation cnvt;

    public:
        Vector() : data(nullptr) {};
             
        Vector(int dimensions, int* dimensionSizes) : dimensions(dimensions), dimensionSizes(dimensionSizes) {
            for (int i = 0; i < dimensions; ++i)
            {
                dataSize *= *dimensionSizes;
                dimensionSizes++;
            }
            data = new T[dataSize]; 
        }
             
        void set(T datum, int* coordinates){
            int position = cnvt(coordinates,dimensionSizes,dimensions);
            T* temp = data+position;
            *temp = datum;
        }
             
        T get(int* coordinates){
            int position = cnvt(coordinates,dimensionSizes,dimensions);
            T* temp = data+position;
            return *temp;            
        }
};

#endif

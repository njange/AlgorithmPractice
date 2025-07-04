
namespace lasd {

/* ************************************************************************** */

template<typename Data>
Vector<Data>::Vector(const unsigned long newSize) {
    elements = new Data[newSize];
    size = newSize;
}

template<typename Data>
Vector<Data>::Vector(const TraversableContainer<Data>& toCopy) : Vector(toCopy.Size()) {
    this->size = toCopy.Size();
    unsigned long i = 0;
    toCopy.Traverse([this, &i](const Data& value){
        (this->elements)[i] = value; i++;
    });
}

template<typename Data>
Vector<Data>::Vector(MappableContainer<Data>&& toMove) noexcept : Vector(toMove.Size()) {
    this->size = toMove.Size();
    unsigned long i = 0;
    toMove.Map([this, &i](Data& value){
        std::swap(this->elements[i], value);
        i++;
    });
}

template<typename Data>
Vector<Data>::Vector(const Vector& toCopy) {
    this->size = toCopy.Size();
    this->elements = new Data[toCopy.Size()];
    for(unsigned long i = 0; i < toCopy.Size(); i++) {
        this->elements[i] = toCopy.elements[i];
    }
}

template<typename Data>
Vector<Data>::Vector(Vector&& toMove) noexcept {
    std::swap(this->size, toMove.size);
    std::swap(this->elements, toMove.elements);
}

template<typename Data>
Vector<Data>::~Vector() {
    delete[] elements;
    elements = nullptr;
}

template<typename Data>
Vector<Data>& Vector<Data>::operator=(const Vector& toCopy) {
    this->Resize(toCopy.Size());
    for(unsigned long i = 0; i < toCopy.Size(); i++) {
        this->elements[i] = toCopy.elements[i];
    }
    return *this;
}

template<typename Data>
Vector<Data>& Vector<Data>::operator=(Vector&& toMove) noexcept {
    this->Clear();
    std::swap(this->size, toMove.size);
    std::swap(this->elements, toMove.elements);
    return *this;
}

template<typename Data>
bool Vector<Data>::operator==(const Vector& toCompare) const noexcept {
    if(this == &toCompare)
        return true;

    if(this->size != toCompare.Size())
        return false;

    if(this->Empty() && toCompare.Empty())
        return true;

    return std::equal(this->elements, this->elements + this->size, toCompare.elements);
}

template<typename Data>
bool Vector<Data>::operator!=(const Vector& toCompare) const noexcept {
    return !(*this == toCompare);
}

template <typename Data>
const Data& Vector<Data>::operator[](unsigned long index) const {
    if(index >= this->Size())
        throw std::out_of_range("Index greater than Size.");
    return this->elements[index];
}

template<typename Data>
const Data& Vector<Data>::Front() const {
    if(this->Empty())
        throw std::length_error("Vector is empty.");
    return this->elements[0];
}

template<typename Data>
const Data& Vector<Data>::Back() const {
    if(this->Empty())
        throw std::length_error("Vector is empty.");
    return this->elements[this->Size() - 1];
}

template<typename Data>
Data& Vector<Data>::operator[](unsigned long index) {
    return const_cast<Data&>(static_cast<const Vector&>(*this)[index]);
}

template<typename Data>
Data& Vector<Data>::Front() {
    return const_cast<Data&>(static_cast<const Vector&>(*this).Front());
}

template<typename Data>
Data& Vector<Data>::Back() {
    return const_cast<Data&>(static_cast<const Vector&>(*this).Back());
}

template <typename Data>
void Vector<Data>::Resize(unsigned long newSize) {
    if (newSize == 0) {
        Clear();
        return;
    }

    if (newSize == size)
        return;

    Data* newElements = new Data[newSize];
    const unsigned long minSize = std::min(this->size, newSize);
    if (elements != nullptr && minSize > 0) {
        std::move(elements, elements + minSize, newElements);
    }

    delete[] elements;
    elements = newElements;
    this->size = newSize;
}

template<typename Data>
void Vector<Data>::Fill(const Data& value) {
    std::fill_n(this->elements, this->Size(), value);
}

template<typename Data>
void Vector<Data>::Clear() {
    delete[] elements;
    elements = nullptr;
    this->size = 0;
}

// SortableVector

template<typename Data>
    requires std::totally_ordered<Data>
SortableVector<Data>::SortableVector(const unsigned long newSize) : Vector<Data>(newSize) {}

template<typename Data>
    requires std::totally_ordered<Data>
SortableVector<Data>::SortableVector(const TraversableContainer<Data>& toCopy) : Vector<Data>(toCopy) {}

template<typename Data>
    requires std::totally_ordered<Data>
SortableVector<Data>::SortableVector(MappableContainer<Data>&& toMove) noexcept : Vector<Data>(std::move(toMove)) {}

template<typename Data>
    requires std::totally_ordered<Data>
SortableVector<Data>::SortableVector(const SortableVector& toCopy) : Vector<Data>(toCopy) {}

template<typename Data>
    requires std::totally_ordered<Data>
SortableVector<Data>::SortableVector(SortableVector&& toMove) noexcept : Vector<Data>(std::move(toMove)) {}

template <typename Data>
    requires std::totally_ordered<Data>
SortableVector<Data>::~SortableVector() {}

template<typename Data>
    requires std::totally_ordered<Data>
SortableVector<Data>& SortableVector<Data>::operator=(const SortableVector& toCopy) {
    this->Resize(toCopy.Size());
    for(unsigned long i = 0; i < toCopy.Size(); i++) {
        this->elements[i] = toCopy.elements[i];
    }
    return *this;
}

template <typename Data>
    requires std::totally_ordered<Data>
SortableVector<Data>& SortableVector<Data>::operator=(SortableVector&& toMove) noexcept {
    if(this != &toMove) {
        std::swap(this->size, toMove.size);
        std::swap(this->elements, toMove.elements);
    }
    return *this;
}

/* ************************************************************************** */

}

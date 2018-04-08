#include <iostream>
#include <type_traits>
#include <utility>
#include <vector>

template <class T> struct is_array { static const bool value = false; };

template <class T> struct is_array<T[]> { static const bool value = true; };

template <class T> struct element_type { using type = T; };

template <class T> struct element_type<T[]> { using type = T; };

template <typename T> class unique_ptr {
  T *p;

public:
  unique_ptr() : p{nullptr} {
  }
  unique_ptr(T *p) : p{p} {
  }
  unique_ptr(const unique_ptr<T> &) = delete;
  unique_ptr(unique_ptr<T> &&o) : p{o.p} {
    o.p = nullptr;
  }
  unique_ptr<T> &operator=(const unique_ptr<T> &) = delete;
  unique_ptr<T> &operator=(unique_ptr<T> &&o) {
    std::swap(p, o.p);
  }
  ~unique_ptr() {
    delete p;
  }

  T &operator*() {
    return *p;
  }
  T &operator[](size_t i) {
    return *(p + i);
  }
};

template <typename T> class unique_ptr<T[]> {
  T *p;

public:
  unique_ptr() : p{nullptr} {
  }
  unique_ptr(T *p) : p{p} {
  }
  unique_ptr(const unique_ptr<T[]> &) = delete;
  unique_ptr(unique_ptr<T[]> &&o) : p{o.p} {
    o.p = nullptr;
  }
  unique_ptr<T[]> &operator=(const unique_ptr<T[]> &) = delete;
  unique_ptr<T[]> &operator=(unique_ptr<T[]> &&o) {
    std::swap(p, o.p);
  }
  ~unique_ptr() {
    delete[] p;
  }

  T &operator*() {
    return *p;
  }
  T &operator[](size_t i) {
    return *(p + i);
  }
};

template <typename T, typename... Args>
typename std::enable_if<!is_array<T>::value, unique_ptr<T>>::type make_unique(Args &&... args) {
  std::cout << "doing it nicely" << std::endl;
  return unique_ptr<T>{new T{std::forward<Args>(args)...}};
}

template <typename T, typename... Args>
typename std::enable_if<is_array<T>::value, unique_ptr<T>>::type make_unique(Args &&... args) {
  std::cout << "doing it arrayly" << std::endl;
  return unique_ptr<T>{
      new typename element_type<T>::type[sizeof...(args)]{std::forward<Args>(args)...}};
}

int main() {
  unique_ptr<std::vector<int>> bal = make_unique<std::vector<int>>(1, 2, 3);
  for (auto x : *bal) {
    std::cout << x << std::endl;
  }
  unique_ptr<int[]> boz = make_unique<int[]>(1, 2, 3);
  for (unsigned int i = 0; i < 3; ++i) {
    std::cout << boz[i] << std::endl;
  }
}

#include<iostream>
#include<memory>
#include <iomanip>

/// <summary>
/// ïåðåêèíóòü â 2 ôàéëà êëàññà
/// </summary>
/// <typeparam name="T"></typeparam>


template<class T>
class Matrix
{
public:
    using num_type = T;
    using size_type = std::size_t;
    using arr_ptr_type = std::shared_ptr<num_type[]>;
private:
    size_type n, m;
    std::shared_ptr<arr_ptr_type[]> a;
public:
    Matrix(std::size_t n, std::size_t m) : n(n), m(m), a(std::make_shared<arr_ptr_type[]>(n))
    {
        for (std::size_t i = 0; i < n; ++i)
            a[i] = std::make_shared<num_type[]>(m);
    }
    num_type& operator()(size_type i, size_type j) {
        return a[i][j];
    }

    size_type getRowCount() { return n; }
    size_type getColCount() { return m; }
    void show()
    {
        for (size_type i = 0; i < n; i++) {
            for (size_type j = 0; j < m; j++)
              std::cout << a[i][j] << ' '<<std::setw(2);
            std::cout << '\n';
        }
    }
    void fill(T value)
    {
        for (size_type i = 0; i < n; i++)
            for (size_type j = 0; j < m; j++)
                a[i][j] = value;
    }
    void Scaling(T max_value)
    {
        T max = a[0][0];
        for (size_type i = 0; i < n; i++)
            for (size_type j = 0; j < m; j++)
                if (max < a[i][j])
                    max = a[i][j];
        float div = float(max_value) / float(max);
        for (size_type i = 0; i < n; i++)
            for (size_type j = 0; j < m; j++)
                a[i][j] *= div;

    }
};
int main() {
    Matrix<int> m(5, 5);
    for (std::size_t i = 0; i < m.getColCount(); i++) 
        for (std::size_t j = 0; j < m.getRowCount(); j++)
            m(i, j) = i - j;
    const int width = 5;
    int size = width;
  /*m.show();
   m.Scaling(127);
    m.show();
    std::cout << '\n';
    m.fill(3);
    m.show();
    m.Scaling(2);
    m.show();
*/
}

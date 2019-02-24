#include "matrix.h"

std::istream& operator >> (std::istream& input_stream, Matrix& matrix)
{
    for (size_t y = 0; y < matrix.GetHeight(); y++)
    {
        for (size_t x = 0; x < matrix.GetWidth(); x++)
        {
            int temp_int = 0;
            input_stream >> temp_int;
            matrix.SetValue(y, x, temp_int);
        }
    }
    return input_stream;
}

std::ostream& operator << (std::ostream& output_stream, const Matrix& matrix)
{
    for (size_t y = 0; y < matrix.GetHeight(); y++)
    {
        for (size_t x = 0; x < matrix.GetWidth(); x++)
        {
            output_stream << matrix.GetValue(y, x) << std::endl;
            //matrix.SetValue(y, x, temp_int);
        }
    }
    return output_stream;
}

Matrix::Matrix(const size_t height, const size_t width)
{
    for (size_t y = 0; y < height; y++)
    {
        std::vector<int> temp_vec;
        for (size_t x = 0; x < width; x++)
        {
            temp_vec.push_back(0);  // все элементы матрицы будут равны нулю
        }
        data_.push_back(temp_vec);
    }
}

size_t Matrix::GetHeight() const
{
    return data_.size();
}

size_t Matrix::GetWidth() const
{
    if (data_.size())
    {
        return data_[0].size();
    }
    return 0;
}

int Matrix::GetValue(const size_t height_index, const size_t width_index) const
{
    int value_ = data_[height_index][width_index];
    return value_;
}

void Matrix::SetValue(const size_t height_index, const size_t width_index,
    const int value)
{
    data_[height_index][width_index] = value;
}

Matrix Matrix::Transpose() const
{
    //Matrix res[matrica[0].size()][matrix.size()];
    Matrix res(data_[0].size() /*height*/, data_.size() /*width*/);
    for (size_t x = 0; x < res.GetWidth(); x++)
    {
        for (size_t y = 0; y < res.GetHeight(); y++)
        {
            res.SetValue(y, x, data_[x][y]);
        }
        return res;
    }
    return Matrix(0, 0); // создаем нулевую, чтобы что-то вернуть
}



Matrix Matrix::operator * (const Matrix& rhs)
{
    /*if (data_[0].size != rhs.GetHeight())
    {
        std::cout << "Умножение невозможно! " << std::endl;
        Matrix res(0, 0);
        return res;
    }*/
    Matrix res(data_.size(), rhs.GetWidth());

    int temp = 0;
    //Matrix3 = new size_t*[Matrix1.GetHeight()];
    for (size_t y = 0; y < data_.size(); y++)
    {
        //Matrix3[i] = new size_t[Matrix2.GetWidth()];
        for (size_t x = 0; x < rhs.GetWidth(); x++)
        {
            //Matrix3[i][j] = 0;
            for (size_t z = 0; z < data_[0].size(); z++)
            {
                temp += data_[y][z] * rhs.GetValue(x, z);
            }
            //res[y][x] = temp;
            res.SetValue(y, x, temp);
            temp = 0;
        }
    }
    return res;
}


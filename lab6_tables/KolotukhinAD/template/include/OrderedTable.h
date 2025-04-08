#include <vector>
#include "Polynomial.h"
#include <iostream>

using namespace std;

template <typename TKey, typename TValue>
class OrderedTable
{
private:
    struct TableRec
    {
        TKey key;
        TValue *value;
    };
    vector<TableRec> data {};
public:

    OrderedTable() {};

    size_t GetSize() const { return data.size(); }

    TValue& operator[](size_t pos) { return &(data[pos].value); }

    void Delete(TKey _key)
    {
        int middle, left = 0, right = data.size();
        while(left <= right)
        {
            middle = (left + right) / 2;
            if ( _key < data[middle].key)
                right = middle - 1;
            else if (_key > data[middle].key)
                left = middle + 1;
            else 
            {
                for (int i = middle; i < data.size() - 1; i++)
                {
                    data[i] = data[i + 1];
                }
                data.pop_back();
            }
        }
    }

    TValue* Find(TKey _key)
    {
        int middle, left = 0, right = data.size();
        while(left <= right)
        {
            middle = (left + right) / 2;
            if ( _key < data[middle].key)
                right = middle - 1;
            else if (_key > data[middle].key)
                left = middle + 1;
            else 
                return data[middle].value;
        }
        return nullptr;
    }
    
    void Insert(TKey _key, TValue value)
    {
        if (data.size() == 0)
        {
            data.push_back({_key, new TValue(value)});
        }
        else if (!Find(_key))
        {
            for (int i = 0; i < data.size(); i++)
            {
                if (data[i].key > _key)
                {
                    data.push_back(data[data.size() - 1]);
                    for (int j = data.size() - 1; j > i; j--)
                    {
                        data[j] = data[j - 1];
                    }
                    delete data[i];
                    data[i] = TableRec{_key, new TValue(value)};
                    return;
                }
            }
            data.push_back({_key, new TValue(value)});
        }
    }

    void Print()
    {
        for (TableRec val : data)
        {
            cout << val.key << ": " << *(val.value) << endl;
        }
    }
};

template <typename TKey>
class PolynomialOrdTable
{
private:
    struct TableRec
    {
        TKey key;
        Polynomial polynomial;
        double result;
    };
    std::vector<TableRec> data {};
public:

    PolynomialOrdTable() {};

    size_t GetSize() const { return data.size(); }

    Polynomial& operator[](size_t pos) { return data[pos].polynomial; }

    void Delete(TKey _key)
    {
        int middle, left = 0, right = data.size();
        while(left <= right)
        {
            middle = (left + right) / 2;
            if ( _key < data[middle].key)
                right = middle - 1;
            else if (_key > data[middle].key)
                left = middle + 1;
            else 
            {
                for (int i = middle; i < data.size() - 1; i++)
                {
                    data[i] = data[i + 1];
                }
                data.pop_back();
            }
        }
    }

    Polynomial* Find(TKey _key)
    {
        int middle, left = 0, right = data.size();
        while(left <= right)
        {
            middle = (left + right) / 2;
            if ( _key < data[middle].key)
                right = middle - 1;
            else if (_key > data[middle].key)
                left = middle + 1;
            else 
                return &data[middle].polynomial;
        }
        return nullptr;
    }

    void Insert(TKey _key, Polynomial _polynomial)
    {
        if (data.size() == 0)
        {
            data.push_back({_key, _polynomial, 0});
        }
        else if (!Find(_key))
        {
            for (int i = 0; i < data.size(); i++)
            {
                if (data[i].key > _key)
                {
                    data.push_back(data[data.size() - 1]);
                    for (int j = data.size() - 1; j > i; j--)
                    {
                        data[j] = data[j - 1];
                    }
                    data[i] = TableRec{_key, _polynomial, 0};
                    return;
                }
            }
            data.push_back({_key, _polynomial, 0});
        }
    }

    void Print()
    {
        for (int i = 0; i < data.size(); i++)
        {
            cout << data[i].key << ": " << data[i].polynomial << " = " << data[i].result << endl;
        }
    }

    void Calculate(Point p)
    {
        for (auto& val : data)
        {
            val.result =  val.polynomial.calculate(p);
        }
    }
};



template <typename TKey>
class PolynomialOrdTableArray
{
private:
    struct TableRec
    {
        TKey key;
        Polynomial polynomial;
        double result;
    };
    size_t capacity;
    size_t size;
    TableRec* table;
public:

    PolynomialOrdTableArray() 
    {
        size = 0;
        capacity = 8; // !
        table = new TableRec[capacity];
    }
    
    ~PolynomialOrdTableArray() 
    {
        delete[] table;
    }

    size_t GetSize() const { return size; }
    
    size_t GetCapacity() const { return capacity; }

    Polynomial& operator[](size_t pos) 
    {
        if (pos < size)
            return table[pos].polynomial;
        throw out_of_range("Index out of range");
    }

    void Delete(TKey key)
    {
        int middle, left = 0, right = size;
        while(left <= right)
        {
            middle = (left + right) / 2;
            if ( key < table[middle].key)
                right = middle - 1;
            else if (key > table[middle].key)
                left = middle + 1;
            else 
            {
                for (int i = middle; i < size - 1; i++)
                {
                    table[i] = table[i + 1];
                }
                size--;
            }
        }
    }

    Polynomial* Find(TKey key)
    {
        int middle, left = 0, right = size;
        while(left <= right)
        {
            middle = (left + right) / 2;
            if (key < table[middle].key)
                right = middle - 1;
            else if (key > table[middle].key)
                left = middle + 1;
            else 
                return &table[middle].polynomial;
        }
        return nullptr;
    }
    
    void Insert(TKey key, Polynomial p) 
    {
        if (!Find(key))
        {
            if (size == capacity)
                resize();
        
            int left = 0; 
            int right = size;
            int mid;
            while (left < right) {
                mid = (right + left) / 2;
                if (table[mid].key > key)
                    right = mid;
                else
                    left = mid + 1;
            }

            if (left < size) {
                for (int i = size; i > left; i--)
                {
                    table[i] = table[i - 1];
                }
                table[left] = {key, p, 0};
            }
            else
            {
                table[size] = {key, p, 0};
            }
            size++;
        }
    }

    void Print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << table[i].key << ": " << table[i].polynomial << " = " << table[i].result << endl;
        }
    }

    void Calculate(Point p)
    {
        for (int i = 0; i < size; i++)
        {
            table[i].result =  table[i].polynomial.calculate(p);
        }
    }

    private: void resize()
    {
        capacity *= 2;
        TableRec* newTable = new TableRec[capacity];
        for (int i = 0; i < size; i++)
        {
            newTable[i] = table[i];
        }
        delete[] table;
        table = newTable;
    }
};

template <typename TKey>
class PolynomialOrdTableList
{
private:
    struct TableRec
    {
        TKey key;
        Polynomial polynomial;
        double result;
    };
    List<TableRec> table {};
public:
    PolynomialOrdTableList() {};

    size_t GetSize() const { return table.getSize(); }

    Polynomial& operator[](size_t pos) { return table[pos].polynomial; }

    void Delete(TKey key)
    {
        for (int i = 0; i < table.getSize(); i++)
        {
            if (table[i].key == key)
            {
                table.removeFrom(i);
                return;
            }
        }
    }

    Polynomial* Find(TKey key)
    {
        for (int i = 0; i < table.getSize(); i++)
        {
            if (table[i].key == key)
            {
                return &table[i].polynomial;
            }
        }
        return nullptr;
    }
    
    void Insert(TKey key, Polynomial polynomial)
    {
        if (Find(key))
            return;
        table.pushBack({key, polynomial});
    }

    void Print()
    {
        for (int i = 0; i < table.getSize(); i++)
        {
            cout << table[i].key << ": " << table[i].polynomial << " = " << table[i].result << endl;
        }
    }

    void Calculate(Point p)
    {
        for (int i = 0; i < table.getSize(); i++)
        {
            table[i].result =  table[i].polynomial.calculate(p);
        }
    }
};

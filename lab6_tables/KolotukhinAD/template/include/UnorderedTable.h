#include <vector>
#include "Polynomial.h"
#include <iostream>

using namespace std;

template <typename TKey, typename TValue>
class Unorderedtable
{
private:
    struct TableRec
    {
        TKey key;
        TValue *value;
    };
    vector<TableRec> data {};
public:

    Unorderedtable() {};

    size_t GetSize() const { return data.size(); }

    TValue& operator[](size_t pos) { return &(data[pos].value); }

    void Delete(TKey key)
    {
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i].key == key)
            {
                data[i] = data[data.size() - 1];
                data.pop_back();
                return;
            }
        }
    }

    TValue* Find(TKey key)
    {
        for (TableRec val : data)
        {
            if (val.key == key)
            {
                return val.value;
            }
        }
        return nullptr;
    }
    
    void Insert(TKey key, TValue value)
    {
        if (Find(key))
            return;
        data.push_back({key, new TValue(value)});
    }


    void Print()
    {
        for (TableRec val : data)
        {
            cout << val.key << ": " << *(val.value) << endl;
        }
    }
};

template <typename TKey, typename TValue>
class UnorderedTableArray
{
private:
    struct TableRec
    {
        TKey key;
        TValue *value;
    };
    int capacity;
    int size;
    TableRec* table;
public:

    UnorderedTableArray() 
    {
        size = 0;
        capacity = 2;
        table = new TableRec[capacity];
    }
    
    ~UnorderedTableArray() 
    {
        for (int i = 0; i < size; i++) 
        {
            delete table[i].value;
        }
        delete[] table;
    }

    size_t GetSize() const { return size; }
    size_t GetCapacity() const { return capacity; }
    TValue& operator[](size_t pos) 
    {
        if (pos < size)
            return *(table[pos].value);
        throw out_of_range("Index out of range");
    }

    void Delete(TKey key)
    {
        for (int i = 0; i < size; i++)
        {
            if (table[i].key == key)
            {
                delete table[i].value;
                table[i] = table[size - 1];
                size--;
                return;
            }
        }
    }

    TValue* Find(TKey key)
    {
        for (int i = 0; i < size; i++)
        {
            if (table[i].key == key)
            {
                return table[i].value;
            }
        }
        return nullptr;
    }
    
    void Insert(TKey key, TValue value)
    {
        if (!Find(key))
        {    
            if (size == capacity)
                resize();
            table[size] = {key, new TValue(value)};
            size++;
        }
    }


    void Print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << table[i].key << ": " << *(table[i].value) << endl;
        }
    }

    private: void resize()
    {
        capacity *= 2; // ограничить maxInt
        TableRec* newTable = new TableRec[capacity];
        for (int i = 0; i < size; i++)
        {
            newTable[i] = table[i];
        }
        delete[] table;
        table = newTable;
    }
};

template <typename TKey, typename TValue>
class UnorderedTableList
{
private:
    struct TableRec
    {
        TKey key;
        TValue *value;
    };
    List<TableRec> table {};
public:
    UnorderedTableList() {};

    size_t GetSize() const { return table.getSize(); }

    TValue& operator[](size_t pos) { return &(table[pos].value); }

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

    TValue* Find(TKey key)
    {
        for (int i = 0; i < table.getSize(); i++)
        {
            if (table[i].key == key)
            {
                return table[i].value;
            }
        }
        return nullptr;
    }
    
    void Insert(TKey key, TValue value)
    {
        if (Find(key))
            return;
        table.pushBack({key, new TValue(value)});
    }

    void Print()
    {
        for (int i = 0; i < table.getSize(); i++)
        {
            cout << table[i].key << ": " << *(table[i].value) << endl;
        }
    }
};


template <typename TKey>
class PolynomialUTable
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

    PolynomialUTable() {};

    size_t GetSize() const { return data.size(); }

    Polynomial& operator[](size_t pos) { return data[pos].polynomial; }

    void Delete(TKey key)
    {
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i].key == key)
            {
                data[i] = data[data.size() - 1];
                data.pop_back();
                return;
            }
        }
    }

    Polynomial* Find(TKey key)
    {
        for (auto& val : data)
        {
            if (val.key == key)
            {
                return &val.polynomial;
            }
        }
        return nullptr;
    }
    
    void Insert(TKey key, Polynomial polynomial)
    {
        if (Find(key))
            return;
        data.push_back({key, polynomial});
    }


    void Print()
    {
        for (auto& val : data)
        {
            cout << val.key << ": " << val.polynomial << " = " << val.result << endl;
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
class PolynomialUTableArray
{
private:
    struct TableRec
    {
        TKey key;
        Polynomial polynomial;
        double result;
    };
    int capacity;
    int size;
    TableRec* table;
public:

    PolynomialUTableArray() 
    {
        size = 0;
        capacity = 2;
        table = new TableRec[capacity];
    }
    
    ~PolynomialUTableArray() 
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
        for (int i = 0; i < size; i++)
        {
            if (table[i].key == key)
            {
                table[i] = table[size - 1];
                size--;
                return;
            }
        }
    }

    Polynomial* Find(TKey key)
    {
        for (int i = 0; i < size; i++)
        {
            if (table[i].key == key)
            {
                return &table[i].polynomial;
            }
        }
        return nullptr;
    }
    
    void Insert(TKey key, Polynomial p)
    {
        if (size == capacity)
            resize();
        if (Find(key))
            return;
        table[size] = {key, p};
        size++;
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
        capacity *= 2; // ограничить maxInt
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
class PolynomialUTableList
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
    PolynomialUTableList() {};

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

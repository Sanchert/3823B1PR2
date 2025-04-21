template<typename TKey, typename TValue>
class HashTable
{
private:
    struct TableRec
    {
        bool deleted = false;
        bool isFree = true;
        TKey key;
        TValue value;
    };
    int capacity;
    int size;
    TableRec* table;

    int Hash(TKey key)
    {
        return key % capacity;
    }

    int HHash(TKey key)
    {
        int p = 3;
        return (Hash(key) + p) % capacity; // (1 ≤ 𝑝 < 𝑀, НОД (𝑝, 𝑀) = 1)
    }

    int FindInd(TKey key)
    {
        int num = -1;
        int ind = Hash(key);
        while (true)
        {
            if (!table[ind].isFree && table[ind].key == key)
            {
                return num = ind;
            }
            if (table[ind].isFree)
            {
                return num;
            }
            ind = HHash(key);
        }
        return num;
    }

public:

    HashTable() :
            size(0),
            capacity(32),
            table(new TableRec[capacity])
    {}
    
    ~HashTable()
    {
        // for (int i = 0; i < capacity; i++)
            // delete table[i];
        delete[] table; 
    }

    size_t GetSize() const
    {
        return size;
    }
    
    size_t GetCapacity() const
    {
        return capacity;
    }
    
    TValue& operator[](size_t pos) 
    {
        if (pos < capacity)
        {
            return table[pos].value;
        }
        throw out_of_range("Index out of range");
    }

    void Delete(TKey key)
    {
        int ind = Hash(key);
        table[ind].deleted = true;
    }

    TValue* Find(TKey key)
    {   
        int ind = FindInd(key);
        if (ind != -1)
            return &table[ind].value;
        return nullptr;
    }
    
    void Insert(TKey key, TValue value)
    {
        int num = -1;
        int ind = Hash(key);
        while(true)
        {
            if (!table[ind].isFree && table[ind].key == key)
            {
                break;
            }
            if (table[ind].deleted && num == -1)
            {
                num = ind;
            }
            if (table[ind].isFree && num == -1)
            {
                table[ind] = TableRec{false, false, key, value};
                break;
            }
            if (table[ind].isFree && num > -1)
            {
                table[num] = TableRec{false, false, key, value};
                break;
            }
            ind = HHash(key);
        }
    }

    void Print()
    {   
        cout << "Hash-Table:" << endl;
        for (int i = 0; i < capacity; i++)
        {
            if (!table[i].isFree)
            {
                cout << table[i].key << ": " << table[i].value << endl;
            }
            else
                cout << "... ..." << endl;
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

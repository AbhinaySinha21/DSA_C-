#include <bits/stdc++.h>
using namespace std;
class Cars
{
    int price;
    int speed;
    string color;

public:
    Cars()
    {
        this->color = "";
        this->price = 0;
        this->speed = 0;
    }

    Cars(int price, int speed, string color)
    {
        this->price = price;
        this->speed = speed;
        this->color = color;
    }
    friend ostream &operator<<(ostream &os, const Cars &dt);
    bool operator>(const Cars *c)
    {
        return this->speed > c->speed;
    }
    bool operator==(const Cars *c)
    {
        return this->speed == c->speed;
    }
};
ostream &operator<<(ostream &output, const Cars &D)
{
    output << "P : " << D.price << " C : " << D.color << "S: " << D.speed;
    return output;
}
template <class T>
class Heap
{
    vector<T> v;
    void upheapify(int ci)
    {
        int pi = (ci - 1) / 2;
        if (v[pi] > v[ci])
        {
            Swap(pi, ci);
            upheapify(pi);
        }
    }
    void downheapify(int pi)
    {
        int lci = 2 * pi + 1;
        int rci = 2 * pi + 2;
        int mini = pi;
        if (lci < v.size() && v[mini] > v[lci])
            mini = lci;
        if (rci < v.size() && v[mini] > v[rci])
            mini = rci;
        if (mini != pi)
        {
            Swap(mini, pi);
            downheapify(mini);
        }
    }

public:
    T min()
    {
        return v[0];
    }
    T size()
    {
        return v.size();
    }
    void Swap(int i, int j)
    {
        T temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
    void add(T item)
    {
        v.push_back(item);
        upheapify(v.size() - 1);
    }
    T remove()
    {
        Swap(0, v.size() - 1);
        int rem = v[v.size() - 1];
        v.pop_back();
        downheapify(0);
        return rem;
    }
    void display()
    {
        for (T i : v)
            cout << *i << "\n";
    }
};
int main()
{
    Heap<Cars *> hp;
    hp.add(new Cars(200, 10, "White"));
    hp.add(new Cars(1000, 20, "Black"));
    hp.add(new Cars(345, 3, "Yellow"));
    hp.add(new Cars(34, 89, "Grey"));
    hp.add(new Cars(8907, 6, "Red"));
    hp.display();
    return 0;
}
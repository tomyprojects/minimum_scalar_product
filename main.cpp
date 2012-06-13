#include <iostream>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

#define throw_if(c) if (c) { throw #c; }

typedef long long data_type;
typedef vector<data_type> vec;
typedef pair<vec,vec> vec_pair;
typedef vector<vec_pair> vec_list;

void read_from_file(const char* name, vec_list & v)
{
    fstream f(name, ios::in);

    throw_if (!f.is_open());

    int n;
    f >> n;

    while (n--)
    {
        int m,j;
        f >> m;

        vec_pair p;

        for (int i=0; i<m; i++)
        {
            f >> j;
            p.first.push_back(j);
        }
        for (int i=0; i<m; i++)
        {
            f >> j;
            p.second.push_back(j);
        }

        v.push_back(p);
    }

    f.close();
}

int minimum_inner_product(vec & v1, vec & v2)
{
    sort (v1.begin(), v1.end(), std::greater<data_type>());
    sort (v2.begin(), v2.end(), std::less<data_type>());

    return inner_product (v1.begin(), v1.end(), v2.begin(), 0);
}

void write_to_file(const char* name, vec & solutions)
{
    fstream f(name, ios::out);

    throw_if (!f.is_open());

    for (int i=0; i<solutions.size(); i++)
    {
        f << "Case #" << i+1 << ": " << solutions[i] << endl;
    }

    f.close();
}

int main()
{
    vec_list v;
    vec p;

    read_from_file ("/Users/tyeung/Google Drive/google code jam/minimum_scalar_product/A-large-practice.in", v);

    for (int i=0; i<v.size(); i++)
    {
        p.push_back( minimum_inner_product(v[i].first, v[i].second) );

        cout << p[i] << endl;
    }

    write_to_file ("/Users/tyeung/Google Drive/google code jam/minimum_scalar_product/A-large-practice.txt", p);

    return 0;
}

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() 
{
    int num, max_mass;

    cin >> num >> max_mass;

    vector<int> cost;
    vector<int> weignt;
    vector<double> price_of_one;

    for (int i = 0; i < num; i++)
    {
        int tmp_cost, tmp_weight;
        cin >> tmp_cost >> tmp_weight;

        cost.push_back(tmp_cost);
        weignt.push_back(tmp_weight);
        price_of_one.push_back((double)tmp_cost/(double)tmp_weight);
    }

    double summ = 0;
    int mass = 0;

    while (1)
    {
        bool find_price = false;
        double max_pr = 0;
        int max_pr_ind = 0;
        for (int i = 0; i < num; i++)
        {
            if (price_of_one[i] == 0)
                continue;

            if (price_of_one[i] > max_pr)
            {
                max_pr = price_of_one[i];
                max_pr_ind = i;
                find_price = true;
            }
        }

        if (!find_price)
            break;

        if (max_mass - mass > weignt[max_pr_ind])
        {
            mass += weignt[max_pr_ind];
            summ += cost[max_pr_ind];
            price_of_one[max_pr_ind] = 0;
        }
        else
        {
            summ += price_of_one[max_pr_ind] * (max_mass - mass);
            break;
        }

    }

    cout << setprecision(18) << summ;

    return 0;
}

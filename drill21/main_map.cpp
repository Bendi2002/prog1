#include "../std_lib_facilities.h"

template <typename m1, typename m2>
void print(const map<m1,m2>& map){
    for(const auto& p : map)
    {
        cout << p.first << ' ' << p.second << '\n';
    }
}

void read(map<string,int>& map){
    string text;
    int number;

    cin >> text >> number;

    map.insert(pair<string,int>(text,number));
}

int main(){
    map<string, int> msi;

    msi["lecture"] = 21;
    msi["lecture2"] = 12;
    msi["lecture5"] = 32;
    msi["lecture3"] = 23;
    msi["lecture7"] = 43;
    msi["lecture9"] = 34;
    msi["lecture8"] = 54;
    msi["lecture1"] = 45;
    msi["lecture4"] = 65;
    msi["lecture6"] = 56;

    print(msi);

    cout << "Erasing...\n";
    msi.erase(msi.begin(),msi.end());
    print(msi);
    cout << '\n';
    cout << "Erasing done!\n";

    cout << "Please insert ten pairs:\n";

    for(int i = 0; i < 10; i++){
        cout << "Pair number " << i+1 << ": ";
        read(msi);
    }
    cout << '\n';

    print(msi);

    int sum = accumulate(msi.begin(),msi.end(),0, [](auto prev_sum, auto &msi_entry){return prev_sum+msi_entry.second;});
    cout << "Sum: " << sum << '\n';

    map<int,string> mis;

    for(auto& mapentry: msi){
        mis[mapentry.second] = mapentry.first;
    }

    print(mis);

    return 0;
}

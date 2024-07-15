#include<bits/stdc++.h>
#include<windows.h>

#define int long long

using namespace std;

vector<int> p;
vector<pair<int, int>> mp;

void makedata()
{
	ofstream fout("input.txt");
	srand(time(nullptr)); 
	std::random_device rd;  
    std::mt19937 gen(rd()); 

    std::uniform_int_distribution<int> distribution(1, 100000000000);

    int num1 = distribution(gen);  // 生成第一个随机数
    int num2 = distribution(gen); 
	int l, r;
	l = num1;
	r = rand() + l  + 100000000;
	cout << l << ' ' << r << '\n';
	mp.push_back({l, r});
	fout.close();
}

int check(int x) {
	int mx = 0, mn = 1e9;
	while (x) {
		mx = max(mx, x % 10);
		mn = min(mn, x % 10);
		x /= 10;
	}
	return (mx - mn);
}

int luckiness(int x) {
    auto s = std::to_string(x);
    auto [pmin, pmax] = std::minmax_element(s.begin(), s.end());
    return *pmax - *pmin;
}

int check_jiangly() {
    int l, r;
    std::cin >> l >> r;
    
    int ans = l;
    int p = 1;
    for (int i = 0; i <= 18; i++) {
        for (int x = 0; x < 10; x++) {
            int v = l / p * p + (p - 1) / 9 * x;
            if (l <= v && v <= r && luckiness(v) < luckiness(ans)) {
                ans = v;
            }
            v = r / p * p + (p - 1) / 9 * x;
            if (l <= v && v <= r && luckiness(v) < luckiness(ans)) {
                ans = v;
            }
        }
        p *= 10;
    
    std::cout << ans << "\n";
}

int check_KY() {

}

int32_t main() {
	ifstream fZ("ZJ_output.txt");
	ifstream fB("BL_output.txt");
	int ans = 0;
	int n = 1000;
	vector<int> Z, B;
	for (int i = 1; i <= n; i ++) {
		makedata();
	}
	// for (int i = 1; i <= n; i++) {
	// 	printf("Test#%lld\n", i);
	// 	// makedata();
	// 	system("ZJ.exe < input.txt > ZJ_output.txt");
	// 	system("BL.exe < input.txt > BL_output.txt");

	// 	// if (system("fc ZJ_output.txt BL_output.txt")) {
	// 	// 	cout << "Wrong Answer!" << endl << endl << endl;
	// 	// 	break;
	// 	// } else {
	// 	// 	cout << "Accepted!" << endl << endl << endl;
	// 	// 	ans ++;
	// 	// }
	// 	int data1, data2;
	// 	while (fZ) fZ >> data1;
	// 	while (fB) fB >> data2;
	// 	fZ.close();
	// 	fB.close();
	// 	cout << data1 << ' ' << data2 << '\n';
	// 	int x = check(data1), y = check(data2);
	// 	cout << x << ' ' << y << '\n';
	// 	if (x != y) {
	// 		cout << "Wrong Answer!" << endl << endl << endl;
	// 		break;
	// 	} else {
	// 		cout << "Accepted!" << endl << endl << endl;
	// 		ans ++;
	// 	}

	// }
	cout << "通过率：" << ans * 1.0 / n * 100 << "%" << endl;

	return 0;
}

#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

vector<int> p;

void makedata()
{
    ofstream fout("input.txt");
    int n = rand() % 10 + 4;
	if (n % 2) n ++;
	p.resize(n + 1);
//	int m = rand() % 5 + 1;
//	int k = rand() % 13 + 1, k = rand() % 13 + 1;
    fout << n << '\n';
	set<int> st;
	for (int i = 1; i <= n; i ++){
		int k = rand() % n + 1;
		if (st.count(k)) {
			i --;
			continue;
		}
		st.insert(k);
		p[i] = k;
		fout << k << ' ';
	}
//	fout << st.size() << '\n';
//	for (auto i : st) fout << i << ' ';
	fout << '\n';
//	for (int i = 1; i <= n; i ++){
//		int k = rand() % n + 1;
//		fout << k << ' ';
//	}
//	fout << '\n';
    fout.close();
}

vector<int> a, b;

bool check() {
	int ac = 0, bc = 0;
	for (int i = 2; i < (int)a.size()  - 1; i ++) {
		if (a[i] + p[i] > a[i - 1] + p[i - 1] && a[i] + p[i] > a[i + 1] + p[i + 1]) ac ++;
	}
	for (int i = 2; i < (int)b.size()  - 1; i ++) {
		if (b[i] + p[i] > b[i - 1] + p[i - 1] && b[i] + p[i] > b[i + 1] + p[i + 1]) bc ++;
	}
	cout << ac << ' ' << bc << '\n';
	return ac == bc;
}

int main() {
    int ans = 0;
	int n = 1000;
    for (int i = 1; i <= n; i++) {
		b.clear();
		a.clear();
		a.push_back(1);
		b.push_back(1);
        printf("Test#%d\n", i);
        makedata();
        system("ZJ.exe < input.txt > ZJ_output.txt");
        system("BL.exe < input.txt > BL_output.txt");
		int x; 
		std::ifstream file1("ZJ_output.txt");
		std::ifstream file2("BL_output.txt");
		freopen("ZJ_output.txt", "r", stdin);
		while (file1 >> x) a.push_back(x);
//		freopen("BL_output.txt", "r", stdin);
		while (file2 >> x) b.push_back(x);
		for (int i = 1; i < p.size(); i ++) cout << p[i] << ' '; cout << '\n';
		for (int i = 1; i < a.size(); i ++) cout << a[i] << ' '; cout << '\n';
		for (int i = 1; i < b.size(); i ++) cout << b[i] << ' '; cout << '\n';
//        if (system("fc ZJ_output.txt BL_output.txt")) {
//            cout << "Wrong Answer!" << endl << endl << endl;
//            break;
//        } else {
//            cout << "Accepted!" << endl << endl << endl;
//            ans ++;
//        }
		if (!check()) {
			cout << "Wrong Answer!" << endl << endl << endl;
			break;
		} else {
			cout << "Accepted!" << endl << endl << endl;
			ans ++;
		}

    }
    cout << "Í¨¹ýÂÊ£º" << ans * 1.0 / n * 100 << "%" << endl;

    return 0;
}

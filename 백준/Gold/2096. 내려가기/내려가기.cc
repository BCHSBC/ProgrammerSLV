#include <iostream>
#include <algorithm>
using namespace std;
int n;
int main() {
	int f, s, t;
	int mf, ms, mt;
	int tf, ts, tt;
	int mmf, mms, mmt;
	int ttf, tts, ttt;
	cin >> n;
	for (int i = 0; i <n; i++) {
		cin >> f >> s >> t;
		if (i == 0) {
			mf = mmf = f;
			ms = mms = s;
			mt = mmt = t;
		}
		else {
			tf = max(mf, ms) + f;
			ts = max(mf, max(ms, mt)) + s;
			tt = max(mt, ms) + t;
			mf = tf, ms = ts, mt = tt;
			ttf = min(mmf, mms) + f;
			tts = min(mmf, min(mms, mmt)) + s;
			ttt = min(mmt, mms) + t;
			mmf = ttf, mms = tts, mmt = ttt;
		}
	}
	cout << max(mf, max(mt, ms)) << " " << min(mmf, min(mms, mmt));
}
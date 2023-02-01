#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

struct Score{
    double score;
    int idx;
    int outlink;
    double inlink;
    string name;
    vector <string> link;
};
map <string,vector<string>> rref;
map <string,double> scc;
vector <Score> sv;
bool comp(Score a,Score b){
    if(a.score == b.score){
        return a.idx < b.idx;
    }
    return a.score > b.score;
}
int solution(string word, vector<string> pages) {
    int answer = 0;
    for(int i = 0;i<word.length();i++){
        word[i] = tolower(word[i]);
    }
    for(int i = 0;i<pages.size();i++){
        Score s;
        string page = pages[i];
        s.outlink = 0;
        s.idx = i;
        s.inlink = 0;
        s.score = 0;
        // 사이트 이름 찾기
        size_t idx = page.find("<meta property=\"og:url\" content=\"https://");
        idx += 41;
        string site = "";
        while(page[idx] != '\"'){
            site += page[idx++];
        }
        //cout << site << "\n";
        s.name = site;
        idx = page.find("body");
        idx += 6;
        string bodyContent = "";
        size_t body = page.find("</body>");
        while(idx < body){
            if(page.substr(idx,17) == "<a href=\"https://"){
                idx += 17;
                string link = "";
                while(page[idx] != '\"'){
                    link += page[idx++];
                }
                s.link.push_back(link);
                idx += 2;
                while(page[idx] != '>') idx++;
                idx++;
                s.outlink += 1;
                rref[link].push_back(s.name);
                //cout << "link: " << link <<"\n";
            }
            bodyContent += tolower(page[idx++]);
        }
        
        //cout << "BODY: " << bodyContent << "\n";
        string tmp = "";
        while((idx=bodyContent.find(word)) != string::npos){
            if(idx == 0 || !(bodyContent[idx-1]>='a'&&bodyContent[idx-1]<='z')){
            idx += word.length();
            char c = bodyContent[idx];
            //cout << "c: " << c <<"\n";
            if(!(c>='a' && c<='z')){
                s.score++;
            }
            }
            bodyContent = bodyContent.substr(idx+1);
        }
        scc[s.name] = s.score;
        if(s.outlink != 0)
            scc[s.name] = s.score/(double)s.outlink;
        sv.push_back(s);
    }
    double max_score = 0;
    for(int i = 0;i<sv.size();i++){
        double sum = 0;
        for(int j = 0;j<rref[sv[i].name].size();j++){
            //cout << ref[sv[i].name][j] << " " << scc[ref[sv[i].name][j]] << "\n";
            sum += scc[rref[sv[i].name][j]];
        }
        sv[i].score += sum;
        if(max_score < sv[i].score){
            max_score = sv[i].score;
            answer = i;
        }
    }
    return answer;
}

#include <iostream>
#include <vector>

#define MAXSIZE 200000

using namespace std;

void fanmeeting();

int main(){
    int numOfTest;
    
    cin >> numOfTest;
    
    if(numOfTest > 20)
        return 1;
    
    for(int i=0; i<numOfTest; i++){
        fanmeeting();
    }
    
    return 0;
}

void fanmeeting(){
    int hugCount = 0;  //동시에 포옹하는 것의 횟수
    int totalHugCount = 0;
    int i, j, k, l;
    string inputHyper, inputFan;
    vector <char> hyperSenior;
    vector <char> fanClub;
    
    //cout << "하이퍼 시니어 멤버 : ";
    cin >> inputHyper;
    
    //cout << "팬클럽 : ";
    cin >> inputFan;
       
    if(inputHyper.size() > inputFan.size() || inputHyper.size()<1 || inputFan.size()<1 || inputHyper.size() > MAXSIZE || inputFan.size() > MAXSIZE)
        return;
    
    for(int i=0; i<inputHyper.size(); i++){
        if(inputHyper[i] != 'F' && inputHyper[i] != 'M')
            return;
        hyperSenior.push_back(inputHyper[i]);
    }
    
    for(int i=0; i<inputFan.size(); i++){
        if(inputFan[i] != 'F' && inputFan[i] != 'M')
            return;
        fanClub.push_back(inputFan[i]);
    }
        
    for(i = 0/*hyperSenior.size()*/; i <= fanClub.size(); i++){
        hugCount = 0;
        
        for(j = 0, k = i; j < hyperSenior.size(); j++, k++){
            if(!fanClub[k])
                break;
            //cout << "hyperSenior[" << j << "] : " << hyperSenior[j] << ", fanClub[" << k << "] : " << fanClub[k] << endl;
            if(hyperSenior[j] == 'F' || fanClub[k] == 'F' || (hyperSenior[j] == 'M' && fanClub[k] == 'F') || !(fanClub[k])){
                hugCount++;
            }
            //cout << "Hug Count : " << hugCount << endl;
        }
        
        if(hugCount == hyperSenior.size()){
            totalHugCount++;
        }
        //cout << "---- total Count : " << totalHugCount << " ------ " << endl;
    }
    
    //cout << "Total hug count : " << totalHugCount << endl;
    cout << totalHugCount << endl;
}

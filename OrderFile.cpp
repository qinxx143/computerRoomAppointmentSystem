//
// Created by Yaobin Qin on 2021/5/26.
//

#include "OrderFile.h"
#include <fstream>
#include "globalFile.h"
#include <map>
//构造函数
OrderFile::OrderFile(){
    //把order file 里面的资料存储到 orderData 里面

    //date:1 interval:1 stuId:1 stuName:杨鸣 roomId:1 status:1
    ifstream ifs;
    ifs.open(ORDER_FILE, ios::out);

    string date;
    string interval;
    string stuId;
    string stuName;
    string roomId;
    string status;

    while(ifs>>date && ifs>>interval &&ifs >>stuId && ifs>> stuName && ifs>>roomId && ifs>>status){
        map<string,string> m;
        this->stringSplitToMap(date, m);
        this->stringSplitToMap(interval, m);
        this->stringSplitToMap(stuId, m);
        this->stringSplitToMap(stuName, m);
        this->stringSplitToMap(roomId, m);
        this->stringSplitToMap(status, m);

//        for(map<string,string>::iterator it=m.begin();it!=m.end(); it++){
//            cout << it->first << ":" << it->second << endl;
//         }
        this->orderData.insert(make_pair(this->size,m));
        this->size++;
    }

    ifs.close();
}

void OrderFile::stringSplitToMap(string str, map<string,string> &m){
    int pos;
    string key;
    string value;

    pos = str.find(":", 0);
    key = str.substr(0,pos);
    value = str.substr(pos+1, str.size()-pos-1);
    m.insert(make_pair(key, value));
}

//更新预约记录
void OrderFile::updateOrder(){

}
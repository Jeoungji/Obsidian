#ifndef ADDR_H_INCLUDED
#define ADDR_H_INCLUDED

#include "member.h"
#include <vector>
#include <list>
//dao:databases access object
class AddrProcess{

    list<Member> datas; //Member ��ü�� �ּ� 10�� ����
    int cnt;  //������ ���� ī��Ʈ

public:
    //������
    AddrProcess():cnt(0){}

    //�迭 ���� �� Member ��ü�� �߰�
    bool addMember(Member &m){
        bool flag = true;
        if(cnt>=9){
            flag = false;
        }else{
            datas.push_back(m);
            //datas[cnt++] = m;
        }
        return flag;
    }

    //��ȣ�� �˻��ؼ� ���ȣ ��ȯ
    int getByNum(int num){
        //for(int i=0;i<cnt;i++){
        //    if(datas[i].getNum() == num){
        //        return i;
        //    }
        //}
        for (list<Member>::iterator itr = datas.begin(), int i = 0; itr != datas.end(); itr++, ++i) {
            if (itr->getNum() == num) {
                return i;
            }
        }
        return -1;//not found ���
    }

    //���ȣ�� ã�Ƽ� �� ��ȯ
    Member* getByIdx(int idx){
        if(idx<0){
            return NULL;
        }
        list<Member>::iterator itr = datas.begin();
        for (int i = 0; i < idx; itr++, ++i) { }
        return (Member*)(itr._Ptr);
    }

    int getCnt(){
        return cnt;
    }

    void setCnt(int cnt) {
        this->cnt = cnt;
    }

    //����
    bool delMember(int idx){
        if(idx<0){
            return false;
        }
        delete datas[idx];
        for(int i=idx;i<cnt-1;i++){
            datas[i] = datas[i+1];
        }
        cnt--;
        return true;
    }

    ~AddrProcess(){
        for(int i=0;i<cnt;i++){
            delete datas[i];
        }
    }

};

#endif // ADDR_H_INCLUDED






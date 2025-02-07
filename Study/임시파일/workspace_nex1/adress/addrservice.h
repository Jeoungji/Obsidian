#ifndef ADDRSERVICE_H_INCLUDED
#define ADDRSERVICE_H_INCLUDED

#include "addr.h"
#include "member.h"
#include <fstream>

//service:����Ͻ� ���� ����
class AddrService{
    AddrProcess pr; //���԰���
    string fname = "addr.dat";
public:
    // ���α׷��� �������ڸ��� �ѹ� ȣ��
    // ���Ͽ� ����� ��ü�� �迭�� �ű�
    void start() {
        // �Է� ��Ʈ��
        ifstream fin;
        // ��Ʈ������ ���� ���� ��ο� ��带 ����
        // ���̳ʸ� �б� ���
        fin.open(fname, ios_base::in | ios_base::binary);
        // ���Ͽ��� ���� 1�� ��ü�� ���� ����
        Member m;
        int cnt = 0;

        if (fin.is_open()) {
            // ��ü�� ������ 1���� �о� m�� ����
            while (fin.read((char*)&m, sizeof(Member))) {
                pr.addMember(new Member(m.getNum(), m.getName(), m.getTel()));
                ++cnt;
            }
            cout << cnt << "���� ��ü�� �迭�� ����" << endl;
            Member::cnt = pr.getByIdx(pr.getCnt() - 1)->getNum();
            fin.close();
        }
    }
    // ���α׷� ����� �ѹ� ȣ��
    void stop() {
        // ���� ��� ��Ʈ�� ����
        // ���� ��� : fname
        // ���� ��� : binary ���� ���
        ofstream fout(fname, ios_base::out | ios_base::binary);

        // ���� ����
        if (fout.is_open()) {
            // �迭���� ��ü �ϳ��� �о� ���Ͽ� ���
            for (int i = 0; i < pr.getCnt(); i++) {
                Member* res = pr.getByIdx(i);
                fout.write((char*)res, sizeof(Member));
            }
        }
        else {
            cout << "File Open Error" << endl;
        }
        fout.close();
    }

    //�߰�
    void add(){
        cout<<"����߰�"<<endl;
        cout<<"name:";
        string name;
        cin>>name;
        string tel;
        cout<<"tel:";
        cin>>tel;
        bool flag = pr.addMember(new Member(name, tel));
        if(flag){
            cout<<"���� ó���� "<<endl;
        }else{
            cout<<"�޸� ���� ���� "<<endl;
        }
    }

    //�˻�
    void printMember(){
        cout<<"��ȣ�� �˻�"<<endl;
        cout<<"num:";
        int num;
        cin>>num;
        Member *res = pr.getByIdx(pr.getByNum(num));
        if(res == NULL){
            cout<<"not found"<<endl;
        }else{
            cout<<"num:"<<res->getNum()<<endl;
            cout<<"name:"<<res->getName()<<endl;
            cout<<"tel:"<<res->getTel()<<endl;
        }
    }

    //����
    void editMember(){
        cout<<"����"<<endl;
        cout<<"edit num:";
        int num;
        cin>>num;
        Member *res = pr.getByIdx(pr.getByNum(num));
        if(res == NULL){
            cout<<"not found"<<endl;
        }else{
            string tel;
            cout<<"new tel:";
            cin>>tel;
            res->setTel(tel);
        }
    }

    //����
    void delMember(){
        cout<<"����"<<endl;
        cout<<"del num:";
        int num;
        cin>>num;
        bool flag = pr.delMember(pr.getByNum(num));
        if(flag){
            cout<<"����ó����"<<endl;
        }else{
            cout<<"�������"<<endl;
        }
    }

    //��ü���
    void printAll(){
        for(int i=0;i<pr.getCnt();i++){
            Member *res = pr.getByIdx(i);
            cout<<"num:"<<res->getNum()<<endl;
            cout<<"name:"<<res->getName()<<endl;
            cout<<"tel:"<<res->getTel()<<endl;
        }
    }

};

#endif // ADDRSERVICE_H_INCLUDED

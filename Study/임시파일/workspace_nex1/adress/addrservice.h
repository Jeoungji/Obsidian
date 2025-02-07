#ifndef ADDRSERVICE_H_INCLUDED
#define ADDRSERVICE_H_INCLUDED

#include "addr.h"
#include "member.h"
#include <fstream>

//service:비즈니스 로직 구현
class AddrService{
    AddrProcess pr; //포함관계
    string fname = "addr.dat";
public:
    // 프로그램이 시작하자마자 한번 호출
    // 파일에 저장된 객체를 배열로 옮김
    void start() {
        // 입력 스트림
        ifstream fin;
        // 스트림에서 읽을 파일 경로와 모드를 지정
        // 바이너리 읽기 모드
        fin.open(fname, ios_base::in | ios_base::binary);
        // 파일에서 읽은 1개 객체를 담을 변수
        Member m;
        int cnt = 0;

        if (fin.is_open()) {
            // 객체가 있으면 1개씩 읽어 m에 저장
            while (fin.read((char*)&m, sizeof(Member))) {
                pr.addMember(new Member(m.getNum(), m.getName(), m.getTel()));
                ++cnt;
            }
            cout << cnt << "개의 객체를 배열에 저장" << endl;
            Member::cnt = pr.getByIdx(pr.getCnt() - 1)->getNum();
            fin.close();
        }
    }
    // 프로그램 종료시 한번 호출
    void stop() {
        // 파일 출력 스트림 생성
        // 파일 경로 : fname
        // 오픈 모드 : binary 쓰기 모드
        ofstream fout(fname, ios_base::out | ios_base::binary);

        // 정상 오픈
        if (fout.is_open()) {
            // 배열에서 객체 하나씩 읽어 파일에 출력
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

    //추가
    void add(){
        cout<<"멤버추가"<<endl;
        cout<<"name:";
        string name;
        cin>>name;
        string tel;
        cout<<"tel:";
        cin>>tel;
        bool flag = pr.addMember(new Member(name, tel));
        if(flag){
            cout<<"정상 처리됨 "<<endl;
        }else{
            cout<<"메모리 부족 오류 "<<endl;
        }
    }

    //검색
    void printMember(){
        cout<<"번호로 검색"<<endl;
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

    //수정
    void editMember(){
        cout<<"수정"<<endl;
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

    //삭제
    void delMember(){
        cout<<"삭제"<<endl;
        cout<<"del num:";
        int num;
        cin>>num;
        bool flag = pr.delMember(pr.getByNum(num));
        if(flag){
            cout<<"정상처리됨"<<endl;
        }else{
            cout<<"삭제취소"<<endl;
        }
    }

    //전체출력
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

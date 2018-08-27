#include <iostream>
#include <fstream>
#include <string>
#include "test.pb.h"

using namespace std;

int main()
{
    /* Write object to file */
    UserList user_list;

    user_list.set_name("用户列表");

    // add person 1
    Person* person;
    Person::Phone *phone;
    person = user_list.add_users();
    person->set_name("cxk");
    person->set_age(30);
    person->set_email("xiankai.chen@qq.com");
    phone = person->add_phonenum();
    phone->set_type(Person::HOME);
    phone->set_id(11111111111);
    phone = person->add_phonenum();
    phone->set_type(Person::MOBILE);
    phone->set_id(22222222222);


    // add person 1
    person = user_list.add_users();
    person->set_name("lgm");
    person->set_age(30);
    person->set_email("77015684@gmail.com");
    phone = person->add_phonenum();
    phone->set_type(Person::HOME);
    phone->set_id(4444444444);
    phone = person->add_phonenum();
    phone->set_type(Person::MOBILE);
    phone->set_id(3333333333);

    fstream output("./data/myinfo.dat", ios::out|ios::binary);
    user_list.SerializeToOstream(&output);
    output.close();
    output.clear();

    /*read object from file*/
    fstream input("./data/myinfo.dat", ios::in|ios::binary);
    UserList userlist_in;
    if(!userlist_in.ParseFromIstream(&input))
    {
        cout << "parse error" << endl;
        return -1;
    }
    cout << "userlist name: "<< userlist_in.name() <<endl;
    for (int i = 0; i < user_list.users_size(); ++i) {
        cout <<"person[" << i << "] name:" << userlist_in.users(i).name()<< endl;
        cout <<"person[" << i << "]  age:" << userlist_in.users(i).age()<< endl;
        cout <<"person[" << i << "]email:" << userlist_in.users(i).email()<< endl;
        for (int j = 0; j < userlist_in.users(i).phonenum_size(); ++j) {
            cout <<"person[" << i << "] phonenum[" << j <<"] type:"<< userlist_in.users(i).phonenum(j).type()<< endl;
            cout <<"person[" << i << "] phonenum[" << j <<"] no:"<< userlist_in.users(i).phonenum(j).id()<< endl;
        }

    }
    input.close();
    input.clear();

    return 0;
}
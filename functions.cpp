#include "header.h"

void createList(List &L){
    first(L) = NULL;
    last(L) = NULL;
}

void createList2(List2 &L){
    first(L) = NULL;
    last(L) = NULL;
}

void createList3(List3 &L){
    first(L) = NULL;
    last(L) = NULL;
}

adr allocate(infotype x){
    adr P = new elm;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}
adr2 allocate2(infotype2 x){
    adr2 P = new elm2;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}
adr3 allocate3(infotype3 x){
    adr3 P = new elm3;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void inLa(List &L, adr P){
    if (first(L) == NULL){
        first(L) = P;
        last(L) = P;
    } else {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

void inLa2(List2 &L, adr2 P){
    if (first(L) == NULL){
        first(L) = P;
        last(L) = P;
    } else {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

void inFi3(List3 &L, adr3 P){
    if (first(L) == NULL){
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}
void inLa3(List3 &L, adr3 P){
    if (first(L) == NULL){
        inFi3(L,P);
    } else {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

void inAf3(List3 &L, adr3 P, adr3 Q){
    if (first(L) == NULL){
        inFi3(L,P);
    } else if (Q == first(L)){
        inFi3(L,P);
    } else {
        prev(P) = prev(Q);
        next(prev(Q)) = P;
        prev(Q) = P;
        next(P) = Q;
    }
}

void delLa3(List3 &L){
    if(first(L) == NULL){
        cout<<"Already empty\n";
    } else {
        adr3 P = last(L);
        last(L) = prev(P);
        next(last(L)) = NULL;
        prev(P) = NULL;
        delete P;
        P = NULL;
    }
}

void clean(List &L){
    if (first(L) == NULL && last(L) == NULL){
        cout<<"Already Empty \n";
    } else {
        adr P;
        while (first(L) != last(L)){
            P = first(L);
            first(L) = next(P);
            delete P;
            P = NULL;
        }
        P = first(L);
        first(L) = NULL;
        last(L) = NULL;
        delete P;
        P = NULL;
    }
}
void clean2(List2 &L){
    if (first(L) == NULL && last(L) == NULL){
        cout<<"Already Empty \n";
    } else {
        adr2 P;
        while (first(L) != last(L)){
            P = first(L);
            first(L) = next(P);
            delete P;
            P = NULL;
        }
        P = first(L);
        first(L) = NULL;
        last(L) = NULL;
        delete P;
        P = NULL;
    }
}
void clean3(List3 &L){
    if (first(L) == NULL && last(L) == NULL){
        cout<<"Already Empty \n";
    } else {
        adr3 P;
        while (first(L) != last(L)){
            P = first(L);
            first(L) = next(P);
            delete P;
            P = NULL;
        }
        P = first(L);
        first(L) = NULL;
        last(L) = NULL;
        delete P;
        P = NULL;
    }
}

void showList(List L){
    if (first(L) == NULL){
        cout<<"List Empty\n";
    } else {
        adr P = first(L);
        while (P != NULL){
            cout<<"Berita "<<info(P).index<<": "<<info(P).like<<", "<<info(P).provoke<<", "<<info(P).comment<<", "<<info(P).emotion<<", "<<info(P).hoax<<endl;
            P = next(P);
        }
    }
}
void showList2(List2 L){
    if (first(L) == NULL){
        cout<<"List Empty\n";
    } else {
        adr2 P = first(L);
        while (P != NULL){
            cout<<"Berita "<<info(P).index<<": "<<info(P).like<<", "<<info(P).provoke<<", "<<info(P).comment<<", "<<info(P).emotion<<", "<<info(P).hoax<<endl;
            P = next(P);
        }
    }
}
void showList3(List3 L){
    if (first(L) == NULL){
        cout<<"List Empty\n";
    } else {
        adr3 P = first(L);
        while (P != NULL){
            cout<<"Distance : "<<info(P).val<<" | Index : "<<info(P).index<<endl;
            P = next(P);
        }
    }
}

void scanDataTrain (List &L, ifstream &file){
    infotype x;
    string like;
    string provokasi;
    string komentar;
    string emosi;
    string hoax;
    std::string::size_type sz;
    int i =1;

    while (file.good()){
        getline(file,like,','); // read by line separated by comma and assign it to variable
        getline(file,provokasi,',');
        getline(file,komentar,',');
        getline(file,emosi,',');
        getline(file,hoax,'\n');

        x.index = i;
        x.like = stoi(like, &sz); // stoi (string to integer)
        x.provoke = stoi(provokasi, &sz);
        x.comment = stoi(komentar, &sz);
        x.emotion = stoi(emosi, &sz);
        x.hoax = stoi(hoax, &sz);

        adr P = allocate(x);
        inLa(L,P);

        i++;
    }
}

void scanDataTest (List2 &L, ifstream &file){
    infotype2 x;
    string like;
    string provokasi;
    string komentar;
    string emosi;
    string hoax;
    std::string::size_type sz;
    int i =4001;

    while (file.good()){
        getline(file,like,','); // read by line separated by comma and assign it to variable
        getline(file,provokasi,',');
        getline(file,komentar,',');
        getline(file,emosi,'\n');

        x.index = i;
        x.like = stoi(like, &sz); // stoi (string to integer)
        x.provoke = stoi(provokasi, &sz);
        x.comment = stoi(komentar, &sz);
        x.emotion = stoi(emosi, &sz);
        x.hoax = 0;

        adr2 P = allocate2(x);
        inLa2(L,P);

        i++;
    }
}

int hoaxGetter (List L, int index){
    adr P = first(L);
    while (info(P).index != index){
        P = next(P);
    }
    if (index == info(P).index){
        return info(P).hoax;
    } else {
        return 0;
    }
}

int classification(int arr[]){ // Classify the hoax value
    int tru = 0;
    int fal = 0;
    for (int i = 0; i < k; i++){
        if(arr[i] == 1){
            tru++;
        } else {
            fal++;
        }
    }
    if (tru > fal){
        return 1;
    } else {
        return 0;
    }
}

int counterList(List3 L){
    if (first(L) == NULL){
        return 0;
    } else {
        int c=0;
        adr3 P = first(L);
        while (P != NULL){
            c++;
            P = next(P);
        }
        return c;
    }
}
void calcDistance(List x, List2 y, List3 &z, int k){
    adr2 Q = first(y); // pointer dataTest
    ofstream output;
    output.open("result.csv");
    int arr[5];
    infotype3 m;
    double d = 0.0; // variable for distance
    int c; // counter
    int hx;
    while (Q != NULL){
        adr P = first(x); // pointer dataTrain
        c = 0;
        while (P != NULL){
            // Use Euclidean Distance
            d = sqrt(pow(info(P).like - info(Q).like,2) + pow(info(P).provoke - info(Q).provoke,2) + pow(info(P).comment - info(Q).comment,2) + pow(info(P).emotion - info(Q).emotion,2));
            m.index = info(P).index;
            m.val = d;
            adr3 R = allocate3(m);
            if (c < k){
                inLa3(z,R);
                c++;
            } else {
                adr3 tmp = first(z);
                while(tmp != NULL){
                    if(info(R).val < info(tmp).val){
                        inAf3(z,R,tmp);
                        delLa3(z);
                        tmp = NULL;
                    } else {
                        tmp = next(tmp);
                    }
                }
            }
            P = next(P);
        }
        adr3 src = first(z);
        int i = 0;
        while (src != NULL){
            arr[i] = hoaxGetter(x,info(src).index);
            i++;
            src = next(src);
        }
        hx = classification(arr);
        info(Q).hoax = hx;
        output<<hx<<endl;
        Q = next(Q);
    }
}


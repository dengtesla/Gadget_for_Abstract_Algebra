#include<bits/stdc++.h>
using namespace std;
int lan = 0;
//srand(19260817);
char g4_0[5][5] = {
{'0'},
{'0','1','a','b','c'},
{'0','a','1','c','b'},
{'0','b','c','1','a'},
{'0','c','b','a','1'}
};
char g6_0[7][7] = {
{'0'},
{'0','1','a','b','c','d','e'},
{'0','a','b','1','d','e','c'},
{'0','b','1','a','e','c','d'},
{'0','c','e','d','1','b','a'},
{'0','d','c','e','a','1','b'},
{'0','e','d','c','b','a','1'}
};
char g9_0[10][10] = {
{'0'},
{'0','1','a','b','c','d','e','f','g','h'},
{'0','a','b','1','e','f','g','h','c','d'},
{'0','b','1','a','g','h','c','d','e','f'},
{'0','c','e','g','d','1','f','a','h','b'},
{'0','d','f','h','1','c','a','e','b','g'},
{'0','e','g','c','f','a','h','b','d','1'},
{'0','f','h','d','a','e','b','g','1','c'},
{'0','g','c','e','h','b','d','1','f','a'},
{'0','h','d','f','b','g','1','c','a','e'}
};
char g10_0[11][11] = {
{'0'},
{'0','1','a','b','c','d','e','f','g','h','i'},
{'0','a','b','c','d','1','f','g','h','i','e'},
{'0','b','c','d','1','a','g','h','i','e','f'},
{'0','c','d','1','a','b','h','i','e','f','g'},
{'0','d','1','a','b','c','i','e','f','g','h'},
{'0','e','i','h','g','f','1','d','c','b','a'},
{'0','f','e','i','h','g','a','1','d','c','b'},
{'0','g','f','e','i','h','b','a','1','d','c'},
{'0','h','g','f','e','i','c','b','a','1','d'},
{'0','i','h','g','f','e','d','c','b','a','1'}
};
char g8_11[9][9] = {
{'0'},
{'0','1','a','b','c','d','e','f','g'},
{'0','a','b','c','1','e','f','g','d'},
{'0','b','c','1','a','f','g','d','e'},
{'0','c','1','a','b','g','d','e','f'},
{'0','d','e','f','g','1','a','b','c'},
{'0','e','f','g','d','a','b','c','1'},
{'0','f','g','d','e','b','c','1','a'},
{'0','g','d','e','f','c','1','a','b'}
};
char g8_12[9][9] = {
{'0'},
{'0','1','a','b','c','d','e','f','g'},
{'0','a','1','c','b','e','d','g','f'},
{'0','b','c','1','a','f','g','d','e'},
{'0','c','b','a','1','g','f','e','d'},
{'0','d','e','f','g','1','a','b','c'},
{'0','e','d','g','f','a','1','c','b'},
{'0','f','g','d','e','b','c','1','a'},
{'0','g','f','e','d','c','b','a','1'}
};
char g8_01[9][9] = {
{'0'},
{'0','1','a','b','c','d','e','f','g'},
{'0','a','b','c','1','g','d','e','f'},
{'0','b','c','1','a','f','g','d','e'},
{'0','c','1','a','b','e','f','g','d'},
{'0','d','e','f','g','1','a','b','c'},
{'0','e','f','g','d','c','1','a','b'},
{'0','f','g','d','e','b','c','1','a'},
{'0','g','d','e','f','a','b','c','1'}
};
char g8_02[9][9] = {
{'0'},
{'0','1','a','b','c','d','e','f','g'},
{'0','a','1','c','b','e','d','g','f'},
{'0','b','c','a','1','f','g','e','d'},
{'0','c','b','1','a','g','f','d','e'},
{'0','d','e','g','f','a','1','b','c'},
{'0','e','d','f','g','1','a','c','b'},
{'0','f','g','d','e','c','b','a','1'},
{'0','g','f','e','d','b','c','1','a'}
};

class group{
private:
    bool illegal;
    bool abelian;
    int ord;
    char mum[25];
    char oper[25][25];
    int order_all[25];
public:
    void init();
    void show();
    void crea(int o,bool abel,int cyc);
    void show_left(char *x,int x_sz,map<char,string> m,int w);
    void show_right(char *x,int x_sz,map<char,string> m,int w);
    void show_quotient(char *x,int x_sz,map<char,string> m,int w);
    void get_order();
    template <typename T,int N,int M>
    void crea_by_user(T (&arr)[N][M],int o);
    bool is_group();
    bool is_abelian();
    bool is_subgroup(char *x,int x_sz);
    bool is_normal_subgroup(char *x,int x_sz);
};
void group::crea(int o,bool abel,int cyc){
    if((o<6||o==7||o==9)&&abel==0)
    {
        if(lan) cout << "No Such Group" << endl;
        else cout << "没有这样的群哦~" << endl << endl;
        illegal = 1;
        return;
    }
    oper[0][0] = '*';
    ord = o;
    abelian = abel;
    if(o==1&&abel==1)
    {
        mum[1] = '1';
        oper[1][1] = '1';
        return;

    }
    mum[1] = '1';
    mum[2] = 'a';
    for(int i=3;i<=o;i++)
    {
        mum[i] = mum[i-1] + 1;
    }
    if(o==2||o==3||o==5||o==7)
    {
        for(int i=1;i<=o;i++)
            for(int j=1;j<=o;j++)
                oper[i][j] = mum[(i+j-2)%o+1];
    }
    if((o==6||o==10)&&abel==1)
    {
        for(int i=1;i<=o;i++)
            for(int j=1;j<=o;j++)
                oper[i][j] = mum[(i+j-2)%o+1];
    }
    if(o==4&&abel==1)
    {
        int w = rand()%2;
        if(cyc==1) w = 0;
        if(cyc==4) w = 1;
        if(w==1)
        for(int i=1;i<=o;i++)
            for(int j=1;j<=o;j++)
                oper[i][j] = g4_0[i][j];
        else
        for(int i=1;i<=o;i++)
            for(int j=1;j<=o;j++)
                oper[i][j] = mum[(i+j-2)%o+1];
    }
    if(o==9&&abel==1)
    {
        int w = rand()%2;
        if(cyc==1) w = 0;
        if(w==1)
        for(int i=1;i<=o;i++)
            for(int j=1;j<=o;j++)
                oper[i][j] = g9_0[i][j];
        else
        for(int i=1;i<=o;i++)
            for(int j=1;j<=o;j++)
                oper[i][j] = mum[(i+j-2)%o+1];
    }
    if(o==10&&abel==0)
    {
        for(int i=1;i<=o;i++)
            for(int j=1;j<=o;j++)
                oper[i][j] = g10_0[i][j];
    }
    if(o==6&&abel==0)
    {
        for(int i=1;i<=o;i++)
            for(int j=1;j<=o;j++)
                oper[i][j] = g6_0[i][j];
    }
    if(o==8&&abel==0)
    {
        int w = rand()%2;
        if(w==1)
        for(int i=1;i<=o;i++)
            for(int j=1;j<=o;j++)
                oper[i][j] = g8_01[i][j];
        else
        for(int i=1;i<=o;i++)
            for(int j=1;j<=o;j++)
                oper[i][j] = g8_02[i][j];
    }
    if(o==8&&abel==1)
    {
        int w = rand()%3;
        if(cyc==1) w = 0;
        if(w==0)
        for(int i=1;i<=o;i++)
            for(int j=1;j<=o;j++)
                oper[i][j] = mum[(i+j-2)%o+1];
        else if(w==1)
        for(int i=1;i<=o;i++)
            for(int j=1;j<=o;j++)
                oper[i][j] = g8_11[i][j];
        else if(w==2)
        for(int i=1;i<=o;i++)
            for(int j=1;j<=o;j++)
                oper[i][j] = g8_12[i][j];
    }
}
void group::show(){
    if(illegal) return;
    if(lan)
    {
        cout << "order: " << ord << endl;
        cout << "The map: " << endl;
    }
    else
    {
        cout << "阶数：" << ord << endl;
        cout << "群表：" << endl;
    }

    cout << "* | ";
    for(int i=1;i<=ord;i++) cout << mum[i] << " ";
    cout << endl;
    for(int i=0;i<=ord+1;i++) cout << "-" << " ";
    cout << endl;
    for(int i=1;i<=ord;i++)
    {
        cout << mum[i] << " | ";
        for(int j=1;j<=ord;j++)
        {
            cout << oper[i][j] << " ";
        }
        cout << endl;
    }
    if(lan) cout << "Is it abelian : " << abelian << endl;
    else cout << "可交换吗：" << abelian << endl;
    get_order();
    if(lan) cout << "The order of every element: " << endl;
    else cout << "各元素的阶：" << endl;
    for(int i=1;i<=ord;i++)
    {
        cout << mum[i] << " ";
    }
    cout << endl;
    for(int i=1;i<=ord;i++)
    {
        cout << order_all[i] << " ";
    }
    cout << endl;
}
void group::init(){
    illegal = 0;
    abelian = 0;
    ord = 0;
    memset(mum,0,sizeof mum);
    memset(oper,0,sizeof oper);
}
void group::get_order(){
    if(illegal) return;
    order_all[1] = 1;
    for(int i=2;i<=ord;i++)
    {
        char w = mum[i];
        int times = 1;
        int num = i;
        while(num!=1)
        {
            times++;
            w = oper[num][i];
            for(int j=1;j<=ord;j++)
            {
                if(mum[j]==w) num = j;
            }
        }
        order_all[i] = times;
    }
}
template <typename T,int N,int M>
void group::crea_by_user(T (&arr)[N][M],int o){
    ord = o;
    mum[1] = '1';
    for(int i=2;i<=o;i++) mum[i] = 'a'+2-i;
    for(int i=1;i<=o;i++)
    {
        for(int j=1;j<=o;j++)
        {
            oper[i][j] = arr[i][j];
        }
    }
}
bool group::is_group(){ ///Small tricks!
    for(int i=1;i<=ord;i++)
    {
        bool flag = 1;
        for(int j=1;j<=ord;j++)
        {
            if(oper[i][j]=='1') flag=0;
        }
        if(flag==1)
        {
            cout << "It's not a group !" << endl;
            group::init();
            group::illegal = 1;
            return 0;
        }
    }
    return 1;
}
bool group::is_abelian(){
    for(int i=1;i<=ord;i++)
    {
        for(int j=1;j<=ord;j++)
        {
            if(oper[i][j]!=oper[j][i])
            {
                abelian = 0;
                return 0;
            }
        }
    }
    abelian = 1;
    return 1;
}
bool group::is_subgroup(char *x,int x_sz){
    for(int i=1;i<=x_sz;i++)
    {
        for(int j=1;j<=x_sz;j++)
        {
            char x1 = x[i];
            char x2 = x[j];
            int xx,yy;
            if(x1=='1') xx = x1 - '0';
            else xx = x1-'a'+2;

            if(x2=='1') yy = x2 - '0';
            else yy = x2-'a'+2;

            char w = oper[xx][yy];
            bool flag = 1;
            for(int k=1;k<=x_sz;k++)
            {
                if(x[k]==w) flag = 0;
            }
            if(flag) return 0;
        }
    }
    for(int i=1;i<=x_sz;i++)
    {
        bool flag = 1;
        for(int j=1;j<=x_sz;j++)
        {
            char x1 = x[i];
            char x2 = x[j];
            int xx,yy;
            if(x1=='1') xx = x1 - '0';
            else xx = x1-'a'+2;

            if(x2=='1') yy = x2 - '0';
            else yy = x2-'a'+2;
            if(oper[xx][yy]=='1') flag = 0;
        }
        if(flag) return 0;
    }
    return 1;
}
bool group::is_normal_subgroup(char *x,int x_sz){
    char w1[x_sz+2];
    char w2[x_sz+2];
    for(int i=1;i<=ord;i++)
    {
        char x1 = mum[i];
        for(int j=1;j<=x_sz;j++)
        {

            char x2 = x[j];
            int xx,yy;
            if(x1=='1') xx = x1 - '0';
            else xx = x1-'a'+2;

            if(x2=='1') yy = x2 - '0';
            else yy = x2-'a'+2;
            w1[j] = oper[xx][yy];
            w2[j] = oper[yy][xx];
        }
        //cout << w1[1] << " " << w2[1] << endl;
        sort(w1+1,w1+x_sz+1);
        sort(w2+1,w2+x_sz+1);
        for(int j=1;j<=x_sz;j++)
        {
            if(w1[j]!=w2[j]) return 0;
        }
    }
    return 1;
}
void group::show_left(char *x,int x_sz,map<char,string> m,int w){
    bool pend[25];
    memset(pend,0,sizeof pend);

    char out[25][25];
    memset(out,0,sizeof out);
    int cnt = 0;
    for(int i=1;i<=ord;i++)
    {
        for(int j=1;j<=x_sz;j++)
        {
            char w = x[j];
            int ww = 0;
            if(w!='1') ww = w-'a'+2;
            else ww =w-'0';
            char q = oper[i][ww];
            int qq = 0;
            if(q!='1') qq = q-'a'+2;
            else qq = q-'0';
            if(pend[qq]) continue;
            //else
            {
                if(j==1) cnt++;
                out[cnt][j] = q;
                pend[qq] = 1;
            }
        }
    }
    if(lan) cout << "This is the left coset : " << endl;
    else cout << "左陪集分解 : " << endl;

    for(int i=1;i<=cnt;i++)
    {
        cout << "{ ";
        for(int j=1;j<x_sz;j++)
        {
            if(w) cout << out[i][j] << " , ";
            else cout << m[out[i][j]] << " , ";
        }
        if(w) cout << out[i][x_sz] << " }" << endl;
        else cout << m[out[i][x_sz]] << " }" << endl;
    }
}
void group::show_right(char *x,int x_sz,map<char,string> m,int w){
    bool pend[25];
    memset(pend,0,sizeof pend);

    char out[25][25];
    memset(out,0,sizeof out);
    int cnt = 0;
    for(int i=1;i<=ord;i++)
    {
        for(int j=1;j<=x_sz;j++)
        {
            char w = x[j];
            int ww = 0;
            if(w!='1') ww = w-'a'+2;
            else ww =w-'0';
            char q = oper[ww][i];
            int qq = 0;
            if(q!='1') qq = q-'a'+2;
            else qq = q-'0';
            if(pend[qq]) continue;

            {
                if(j==1) cnt++;
                out[cnt][j] = q;
                pend[qq] = 1;
            }
        }
    }
    if(lan) cout << "This is the right coset : " << endl;
    else cout << "右陪集分解 : " << endl;

    for(int i=1;i<=cnt;i++)
    {
        cout << "{ ";
        for(int j=1;j<x_sz;j++)
        {
            if(w) cout << out[i][j] << " , ";
            else cout << m[out[i][j]] << " , ";
        }
        if(w) cout << out[i][x_sz] << " }" << endl;
        else cout << m[out[i][x_sz]] << " }" << endl;
    }
}
void group::show_quotient(char *x,int x_sz,map<char,string> m,int w){
    bool pend[25];
    memset(pend,0,sizeof pend);

    char out[25][25];
    memset(out,0,sizeof out);
    int cnt = 0;
    for(int i=1;i<=ord;i++)
    {
        for(int j=1;j<=x_sz;j++)
        {
            char w = x[j];
            int ww = 0;
            if(w!='1') ww = w-'a'+2;
            else ww =w-'0';
            char q = oper[i][ww];
            int qq = 0;
            if(q!='1') qq = q-'a'+2;
            else qq = q-'0';
            if(pend[qq])continue;

            {
                if(j==1) cnt++;
                out[cnt][j] = q;
                pend[qq] = 1;
            }
        }
    }
    if(lan) cout << "This is the quotient group : " << endl;
    else cout << "商群 : " << endl;

    for(int i=1;i<=cnt;i++)
    {
        cout << "{ ";
        for(int j=1;j<x_sz;j++)
        {
            if(w) cout << out[i][j] << " , ";
            else cout << m[out[i][j]] << " , ";
        }
        if(w) cout << out[i][x_sz] << " }" << endl;
        else cout << m[out[i][x_sz]] << " }" << endl;
    }
}
void func1(){
    group qun;
    unsigned int n;
    if(lan) cout << "Enter the order: ";
    else cout << "请输入阶数：";
    cin >> n;
    if(n>10)
    {
        if(lan) cout << "the order is too large!" << endl;
        else cout << "阶数过大！" << endl;
    }
    else
    {
        if(lan) cout << "Is it abelian?(1/0)";
        else cout << "是否为可交换群(1/0) ：";
        bool ab;
        cin >> ab;
        qun.init();
        qun.crea(n,ab,0);
        qun.show();
    }
}
void func2(){
    if(lan) cout << "Use the group saved in the program?(1/0)";
    else cout << "使用程序自带的群吗(1/0)";
    int w;
    cin >> w;
    group qun;
    map<string,char> m;
    map<char,string> m2;
    if(w)
    {
        if(lan) cout << "Choose the group you want:" << endl;
        else cout << "填写序号选择需要的群:" << endl;
        if(lan)
        {
            cout << "Zi : the i-th cyclic group (0<i<11)" << endl;
            cout << "K4 : Klein four-group" << endl;
            cout << "S3 : the symmetric group of degree 3" << endl;
        }
        else
        {
            cout << "Zi : i阶循环群(0<i<11)" << endl;
            cout << "K4 : 克莱因四元群" << endl;
            cout << "S3 : 3次对称群" << endl;
        }
        string kk;
        cin >> kk;
        if(kk[0]== 'Z')
        {
            if(kk[1]=='1'&&kk[2]=='0')
            {
                qun.crea(10,1,1);
            }
            else qun.crea(kk[1]-'0',1,1);
        }
        else if(kk[0]=='K')
        {
            qun.crea(4,1,0);
        }
        else if(kk[0]=='S')
        {
            qun.crea(6,0,0);
        }
    }
    else
    {
        if(lan) cout << "Enter the Order : ";
        else cout << "请输入阶数 : ";
        int ord;
        cin >> ord;
        if(lan) cout << "Enter the Symbol of the Unit : ";
        else cout << "输入单位元的符号 : ";
        string w1;
        cin >> w1;
        m[w1] = '1';
        m2['1'] = w1;
        if(lan) cout << "Enter the Symbol of the others (use blankspace to split) : ";
        else cout << "输入其他元素的符号(用空格隔开) : ";

        for(int i=2;i<=ord;i++)
        {
            string w;
            cin >> w;
            m[w] = i+'a'-2;
            m2[i+'a'-2] = w;
        }

        if(lan)
        {
            cout << "Enter the map of this group(In order of the number you have enterd before) : " << endl;
            cout << "For example : if you want to get a Z3, and you enterd '1 2 3'just now (let '1' be the unit), You can enter : " << endl;
        }
        else
        {
            cout << "输入你的群表（按之前输入元素的顺序，第一个为单位元） : " << endl;
            cout << "例：假如你想要一个Z3，并且你刚输入的元素为'1 2 3' (其中1为单位元)，你可以输入：" << endl;
        }
        cout << "1 2 3" << endl;
        cout << "2 3 1" << endl;
        cout << "3 1 2" << endl;
        if(lan)
        {
            cout << "which means : " << endl;
        }
        else
        {
            cout << "意思是 : " << endl;
        }
        cout << "1*1=1,1*2=2,1*3=3" << endl;
        cout << "2*1=2,2*2=3,2*3=1" << endl;
        cout << "3*1=3,3*2=1,3*3=2" << endl;
        cout << endl;

        char val[25][25];
        for(int i=1;i<=ord;i++)
        {
            for(int j=1;j<=ord;j++)
            {
                string test;
                cin >> test;
                val[i][j] = m[test];
            }
        }
        qun.crea_by_user(val,ord);
    }
    if(lan) cout << "Input The number of elements in your subgroup : ";
    else cout << "输入你的子群的大小(元素个数) : ";
    int x_sz;
    cin >> x_sz;
    if(lan)
    {
        cout << "Input your subgroup/Normal subgroup(Input the element,Use blankspace to split)" << endl;
        cout << "The element(default) in this program is 1,a,b,c,d,... and 1 is the Unit." << endl;
    }
    else
    {
        cout << "输入你的子群/正规子群(输入元素即可，用空格分割不同的元素)" << endl;
        cout << "程序中默认的元素为1,a,b,c,d,... 1为单位元" << endl;
    }
    string x_temp;
    char x[25];
    for(int i=1;i<=x_sz;i++)
    {
        cin >> x_temp;
        if(!w) x[i] = m[x_temp];
        else x[i] = x_temp[0];
        //cout << x[i] << endl;
    }
    if(qun.is_normal_subgroup(x,x_sz)&&qun.is_subgroup(x,x_sz))
    {
        if(lan) cout << "This is a normal subgroup" << endl;
        else cout << "这是一个正规子群" << endl;
        qun.show_quotient(x,x_sz,m2,w);
    }
    else if(qun.is_subgroup(x,x_sz))
    {
        if(lan) cout << "This is a subgroup" << endl;
        else cout << "这是一个子群" << endl;
        qun.show_left(x,x_sz,m2,w);
        qun.show_right(x,x_sz,m2,w);
    }
    else
    {
        if(lan) cout << "This is not a group!" << endl;
        else cout << "这不是子群！" << endl;
    }
}

int main(){
    cout << "语言/language : 0-中文 1-英文" << endl;
    cin >> lan;
    if(lan)
    {
        cout << "Gadget for Abstract Algebra v1.0   ---by D_Tesla" << endl;
        cout << "Only the groups below 10th order is supported to generate." << endl;
        cout << "Only the groups below 20th order is supported to check." << endl;
        cout << "Enter the number for different function:" << endl;
        cout << "1:generate a group below 10th order" << endl;
        cout << "2:Left and Right Coset/Factorization of Quotient Group" << endl;
    }
    else
    {
        cout << "近世代数小工具v1.0   ---by D_Tesla" << endl;
        cout << "暂时仅支持10阶以下的群的生成/20阶以下的群的检验" << endl;
        cout << "输入不同的数字进入相应功能：" << endl;
        cout << "1：生成一个不超过10阶的群" << endl;
        cout << "2：陪集分解/求商群" << endl;
    }


    int t;
    while(cin >> t)
    {
        if(t==1)
        {
            func1();
        }
        if(t==2)
        {
            func2();
        }

        if(lan)
        {
            cout << endl << endl << "Enter the number for different function:" << endl;
            cout << "1:generate a group below 10th order" << endl;
            cout << "2:Factorization of Quotient Group" << endl;
        }
        else
        {
            cout << endl << endl << "输入不同的数字进入相应功能：" << endl;
            cout << "1：随机生成一个群" << endl;
            cout << "2：陪集分解/求商群" << endl;
        }

    }
}




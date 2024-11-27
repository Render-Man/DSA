#include<bits/stdc++.h>
using namespace std;

#define sw std::setw
#define lft std::left


struct NhanVien
{
	char hoDem[20];
	char ten[15];
	char gioiTinh[5];
	char maNV[10];
	float heSoLuong;	
};

struct Node
{
	NhanVien nv;
	Node* next;
	
	Node() : next(NULL) {
	}
};

typedef Node* L;

L lst;

void create(L& l)
{
	l = NULL;
}

bool isempty(L& l)
{
	return l == NULL;
}

NhanVien getnv()
{
	cout<<"nhap nhan vien:";
	NhanVien nv;
	
	//fflush(stdin);
	cout<<"ma: ";
	cin.getline(nv.maNV, 10);
	
	cout<<"Nhap ho dem: ";
	cin.getline(nv.hoDem, 20);
	cout<<"Nhap ten: ";
	cin.getline(nv.ten, 15);
	cout<<"Nhap gioi tinh: ";
	fflush(stdin);
	gets(nv.gioiTinh);
	cout<<"Nhap he so luon: ";
	
	cin>>nv.heSoLuong;
	cin.ignore();
	
	return nv;
}

void show(L& l);


prth()
{
	cout<<lft<<sw(10)<<"Ma nv"<<sw(20)<<"Ho dem"<<sw(15)<<"Ten"<<sw(10)<<"gioi tinh"<<sw(10)<<"he so luong"<<endl;
}

void prt(NhanVien n)
{
	cout<<lft<<sw(10)<<n.maNV<<sw(20)<<n.hoDem<<sw(15)<<n.ten<<sw(10)<<n.gioiTinh<<sw(10)<<n.heSoLuong<<endl;
}

void add(L& l, NhanVien nv)
{
	Node* nn = new Node;
	nn->nv = nv;
	
	if(isempty(l))
	{
		l = nn;
		return;
	}
	
	Node* c = l;
	while(c->next != NULL)
	{
		c = c->next;
	}
	
	c->next = nn;
}

int timNV(L& l)
{
	cout<<"Nhap ma can tim: ";
	char m[10];
	cin.getline(m, 10);
	
	Node* c = l;
	while(c != NULL)
	{
		NhanVien nv = c->nv;
		if(strcmp(nv.maNV, m) == 0)
		{
			cout<<"Thong tin nhan vien can tim: "<<endl;
			prt(nv);
			
			Node* nxt = c->next;
			if(nxt != NULL)
				c->next = nxt->next;
			else
				c->next = NULL;
			
			cout<<"Danh sach sau khi xoa";
			show(l);
			break;
		}
		c = c->next;
	}
}

void insrt(L& l)
{
	NhanVien nv = getnv();
	Node* nn = new Node;
	nn->nv = nv;
	nn->next = l;
	l = nn;
}

void sort(L& l)
{
	Node* ci = l;
	
	while(ci != NULL)
	{
		Node* cj = ci->next;
		Node* cmj = ci;
		
		while(cj != NULL)
		{
			if(cj->nv.heSoLuong < cmj->nv.heSoLuong)
			{
				cmj = cj;
			}
			cj = cj->next;
		}
		
		if(cmj != ci)
		{
			NhanVien n = cmj->nv;
			cmj->nv = ci->nv;
			ci->nv = n;
		}
		ci = ci->next;
	}
}

void show(L& l)
{
	prth();
	Node* c = l;
	while(c != NULL)
	{
		NhanVien n = c->nv;
		prt(n);
		c = c->next;
	}
}

void delAt(L& l, int k)
{
	if(k == 1)
	{
		if(isempty(l))
			l = NULL;
		else
			l = l->next;
		return;
	}
	Node* c = l;
	int i = 1;
	while(c != NULL)
	{
		if(i + 1 == k)
		{
			Node* l = c->next;
			
			if(l->next == NULL)
			{
				c->next = NULL;	
			}	
			else
			{
				c->next = l->next;
			}
			return;
		}
		
		c = c->next;
		i++;
	}
	
	cout<<"ko co";
}

int main()
{
	create(lst);
	cout<<"Nhap vao ds it nhat 3 ptu"<<endl;
	for(int i = 0; i < 3; i++)
	{
		add(lst, getnv());
	}
	
	while(true)
	{
		cout<<"Nhap tiep? - 1 de tiep, 2 la dung";
		int k;
		cin>>k;
		cin.ignore();
		if(k == 1)
			add(lst, getnv());
		else if(k == 2)
			break;
		else
		{
			cout<<"ko co lua chonj"<<endl;
			continue;
		}
	}
	
	show(lst);
	timNV(lst);
	insrt(lst);
	sort(lst);
	cout<<"Danh sach sau khi sx"<<endl;
	show(lst);
}

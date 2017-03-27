#include <stdio.h>
#include <tchar.h>
#include <conio.h>
#include <stdlib.h>

struct BinaryTree
{
	float value;
	BinaryTree* left;
	BinaryTree* right;
};
BinaryTree *NewTree(int value)
{
	BinaryTree *New = (BinaryTree*)malloc(sizeof(BinaryTree));
	New->left=NULL;
	New->right=NULL;
	New->value=value;
	return New;
}
void Insert(BinaryTree *ptr,float value)
{
	
	if(ptr!=NULL){
		BinaryTree *tmp=ptr;
		while(1)
		{
			if (value<tmp->value){
				if(tmp->left!=NULL) tmp=tmp->left;
				else{
					tmp->left=NewTree(value);
					return;
				}
			}
			if (value > tmp->value){
				if(tmp->right!=NULL) tmp=tmp->right;
				else{
					tmp->right=NewTree(value);
					return;
				}
			}
		}
	}
}

void ShowTree(BinaryTree *ptr)
{
	if(ptr)
	{
	
	printf("%f\n",ptr->value);
	if(ptr->left!=NULL)
	{
		printf("Na lewo od %f jest ",ptr->value);
	ShowTree(ptr->left);
	}
	if(ptr->right!=NULL)
	{
	printf("Na prawo od %f jest ",ptr->value);
	ShowTree(ptr->right);
	}
	}else if(ptr == NULL)
	{
		printf("Drzewo jest puste\n");
	}
}
void ShowData(BinaryTree *ptr) //pokaznie warosci w danym node;
{
	printf("\nWartosc przechowywana wpodanym wezle to %f",ptr->value);
}
void ShowInorder(BinaryTree *ptr)
{
	if(ptr)
	{
		ShowInorder(ptr->left);
		printf("%f ",ptr->value);
		ShowInorder(ptr->right);
	}
}
void ShowPostorder(BinaryTree *ptr)
{
	if(ptr)
	{
		ShowPostorder(ptr->left);
		ShowPostorder(ptr->right);
		printf("%f ",ptr->value);
	}
}
void ShowPreorder(BinaryTree *ptr)
{
	if(ptr)
	{
		printf("%f ",ptr->value);
		ShowPreorder(ptr->left);
		ShowPreorder(ptr->right);
	}
}
float MaxDepth(BinaryTree *ptr) // glebokosc drzewa(ilosc wezlow);
{
	if(ptr)
	{	
		float depthL=MaxDepth(ptr->left);
		float depthR=MaxDepth(ptr->right);

		if(depthL>depthR)
			return depthL+1;
		else return depthR+1;
	}
	else return 0;
}
float Size(BinaryTree *ptr) // rozmiar drzewa
{
	if(ptr)
	{
		return 1+Size(ptr->left)+Size(ptr->right);
	}
	else return 0;
}
float Max(BinaryTree *ptr) //maxymalna wartosc  w drzewie
{
	if(ptr)
	{
		while(ptr->right!=NULL)
		{
			ptr=ptr->right;
		}
			return ptr->value;
	}
	else
	{
		printf("Puste drzewo !!");
		return EXIT_FAILURE;
	}
}
float Min(BinaryTree *ptr) //minimalna wartosc w drzewie
{
	if(ptr)
	{
		while(ptr->left!=NULL)
		{
			ptr=ptr->left;
		}
			return ptr->value;
	}
	else
	{
		printf("Puste drzewo !!");
		return EXIT_FAILURE;
	}
}
void MirrorTree(BinaryTree **ptr) // lustrzane odbicie drzewa (zmiana na drzewie)
{
	if((*ptr)!=NULL)
	{
		BinaryTree *temp=NULL;

		MirrorTree(&(*ptr)->left);
		MirrorTree(&(*ptr)->right);
		
		temp=(*ptr)->left;
		(*ptr)->left=(*ptr)->right;
		(*ptr)->right=temp;

	}
	else 
	{
		
	}
}
void DeleteTree(BinaryTree *ptr)
{
	if(ptr!=NULL)
	{
		DeleteTree(ptr->left);
		DeleteTree(ptr->right);
		free(ptr);
	}
	
}
bool Rotation(BinaryTree **ptr,int kierunek)
{
	BinaryTree *temp;
	BinaryTree *temp1;
	BinaryTree *temp2;
	BinaryTree *temp3;
	BinaryTree *temp4;
	BinaryTree *temp5;
	BinaryTree *temp6;
	if((*ptr)->left==NULL && kierunek == 2)
	{
		printf("nie da sie rotowac drzewa\n");
		return false;
	}
	else if((*ptr)->right==NULL && kierunek == 1)
	{
		printf("nie da sie rotowac drzewa\n");
		return false;
	}
	else
	{
		temp=(*ptr);//root
		temp4=(*ptr)->left;//lewo
		temp5=(*ptr)->left->right;//lewo prawo
		temp6=(*ptr)->left->left;//lewo lewo
		temp1=(*ptr)->right;//prawo
		temp2=(*ptr)->right->right;//prawo prawo
		temp3=(*ptr)->right->left;//prawo lewo
	

	if(kierunek==2 ){//w prawo
			(*ptr)=temp4;
			(*ptr)->right=temp;
			(*ptr)->right->right=temp1;
			(*ptr)->left=temp6;
			(*ptr)->right->left=temp5;
			return true;

	}else if(kierunek == 1){// w lewo
			(*ptr)=temp1;
			(*ptr)->left=temp;
			(*ptr)->left->left=temp4;
			(*ptr)->right=temp2;
			(*ptr)->left->right=temp3;
			return true;
	}
	
	}
}
BinaryTree *SerchNode(BinaryTree *ptr,float value) //wyszukanie node przekazanie wskaznika do niego
{
	if(ptr)
	{
	if(ptr->value==value)
	{
		return ptr;
	}
	else if(ptr->value>value)
	{
		return SerchNode(ptr->left,value);
	}
	else if(ptr->value<value)
	{
		return SerchNode(ptr->right,value);
	}else if(ptr->value!=value)
	{
		
		printf("\nZaden wezel nie przechowuje takiej wartosci");
		return 0;
	
	}
	}else
	{
		printf("\nZaden wezel nie przechowuje takiej wartosci");
		return 0;
	}
}
void Menu()
{
	printf("Opcje\n1)Wyswietl Inorder\n2)Wyswietl Postorder\n3)Wyswietl Preorder\n4)Jaki jest depth ?\n5)Jaki jest size ?\n");
	printf("6)Max liczba\n7)Min liczba\n8)Lustrzane odbicie\n9)Rotacja Lewo\n10)Rotacja Prawo\n11)Pokaz Drzewo\n");
}
int main()
{
	float depth = 0;
	float size =0;
	float max =0;
	float min=0;
	int ilosc=0;
	int wybor =0;
	float liczba = 0;
	bool qq=true;
	BinaryTree* temp=(BinaryTree*)malloc(sizeof(BinaryTree));
	BinaryTree* tree=NULL;
	printf("\nRoot : ");
	ShowTree(tree);
	printf("Ile wartosci wpisac do drzewa ? : ");
	scanf("%d",&ilosc);
	
	for(int i=0;i<ilosc;i++)
	{
		printf("Podaj wartosc %d : ",i+1);
		scanf("%f",&liczba);
		if(i==0) tree=NewTree(liczba);
		else Insert(tree,liczba);
	}
	Menu();
	scanf("%d",&wybor);
	while (1)
	{
		qq=true;
		switch(wybor)
		{
		case 1:
			printf("Inorder : ");
			ShowInorder(tree);
			break;
		case 2:
			printf("\nPostorder : ");
			ShowPostorder(tree);
			break;
		case 3:
			printf("\nPreorder : ");
			ShowPreorder(tree);
			break;
		case 4:
			depth = MaxDepth(tree);
			printf("\nDepth : %f",depth);
			break;
		case 5:
			size = Size(tree);
			printf("\nSize : %f",size);
			break;
		case 6:
			max=Max(tree);
			printf("\nMax : %f",max);
			break;
		case 7:
			min=Min(tree);
			printf("\nMin : %f",min);
			break;
		case 8:
			printf("\nDrzewo w odbicu lustrzanym\n");
			MirrorTree(&tree);
			break;
		case 9:
			qq=Rotation(&tree,1);
			break;
		case 10:
			qq=Rotation(&tree,2);
			break;
		case 11:
			if(qq==true)
			{
				printf("\nRoot : ");
				ShowTree(tree);
			}
			break;

		}
		_getch();
		system("cls");
		Menu();
	scanf("%d",&wybor);
	}

	
	
	
	
	
	temp=SerchNode(tree,5);//skopiowanie wezla do nowego drzewa
	if(temp!=NULL)
	{
	ShowData(temp);
	printf("\nInorder : ");
	ShowInorder(temp);
	printf("\nPostorder : ");
	ShowPostorder(temp);
	printf("\nPreorder : ");
	ShowPreorder(temp);
	depth = MaxDepth(temp);
	printf("\nDepth : %f",depth);
	size = Size(temp);
	printf("\nSize : %f",size);
	max=Max(temp);
	printf("\nMax : %f",max);
	min=Min(temp);
	printf("\nMin : %f",min);
	}
	_getch();
	DeleteTree(tree);
	
	
	
	return 0;
}

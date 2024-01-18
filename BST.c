#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct BSTnode *tp;
struct BSTnode
{
	int key;
	tp right;
	tp left;
};
tp root = NULL;	
	
bool exist(tp aux, int data);
void TreeTraversal(tp aux);
void insert1(tp *x, int data);
void insert2(tp *x, tp *y);
void delete(tp *x, int data);
tp findmin(tp x);
tp findmax(tp x);

int main()
{
	
	int daa;
	int choice = 1;
	while (choice)
	{
		char xar;
		printf("\nEnter I to insert, D to delete, P to print, m for minimum key, M for maximum key, R for root and E to exit.\n");
		scanf("%c", &xar);
		switch (xar)
		{
		case 'I':
			{
				printf("\n Enter data = ");
				scanf("%d", &da);
				if(root == NULL)
				{		
					tp newnode = (tp)malloc(sizeof(struct BSTnode)); //Dimiourgia node
					newnode->key = da;
					newnode->left = NULL;
					newnode->right = NULL;
					root = newnode;
					printf("\nroot = %d", root->key);
				}
				else
					insert1(&root, da);		
			}
			break;
		case 'D':
			{
				printf("\n Enter data = ");
				scanf("%d", &da);
				if(exist(root, da) == 1)
					delete(&root, da);	
				else
					printf("\nThere is no key = %d to delete!", da);
				break;
			}	
		case 'P':
			{
				if(root == NULL)
					printf("\nTree is empty!");
				else
					TreeTraversal(root);	
				break;
			}
		case 'm':
			{
				if(root != NULL)
					printf("\nThe minimum key is: %d", findmin(root)->key);
				else
					printf("\nThe are not elements in the tree!");
				break;
			}
		case 'M':
			{
				if(root != NULL)
					printf("\nThe maximum key is: %d", findmax(root)->key);
				else
					printf("\nThe are not elements in the tree!");
				break;
			}
		case 'R':
			{
				if(root != NULL)
					printf("\nThe root is %d", root->key);
				else
					printf("\nTree is empty!");		
				break;
			}
		case 'E':
				choice = 0;
				break;
		default:
			printf("Wrong input!");
		}
		getchar();
	}
	return 0;
}


void TreeTraversal(tp aux)
{
	if(aux->left != NULL)
		TreeTraversal(aux->left);
	printf("%d, ", aux->key);
	if(aux->right != NULL)
		TreeTraversal(aux->right);	
}
bool exist(tp aux, int data)
{
	if(aux == NULL)
		return 0;
	else if(aux->key == data)
		return 1;
	else if((aux->key > data) && (aux->left != NULL))
		exist(aux->left, data);
	else if((aux->key < data) && (aux->right != NULL))
		exist(aux->right, data);
	else
		return 0;		
}

void insert1(tp *x, int data)
{
	if(data == (*x)->key)
	{
		printf("\nThis key = %d, is already in the Tree!", data);
		return;
	}
	if(data < (*x)->key)
	{
		if((*x)->left != NULL)
		{
			insert1(&((*x)->left), data);
		}
		else
		{	
			tp newnode = (tp)malloc(sizeof(struct BSTnode)); //Dimiourgia node
			newnode->key = data;
			newnode->left = NULL;
			newnode->right = NULL;
			(*x)->left = newnode;
			printf("\nparent of %d = %d", (*x)->left->key, (*x)->key);
			printf("\nleftchild of %d = %d", (*x)->key, newnode->key);
			printf("\nroot of %d = %d", (*x)->left->key, root->key);
			return;
		}
	}
	else if(data > (*x)->key)
	{
		if((*x)->right != NULL)
		{
			insert1(&((*x)->right), data);
		}
		else
		{
			tp newnode = (tp)malloc(sizeof(struct BSTnode)); //Dimiourgia node
			newnode->key = data;
			newnode->left = NULL;
			newnode->right = NULL;
			(*x)->right = newnode;
			printf("\nparent of %d = %d", (*x)->right->key, (*x)->key);
			printf("\nrightchild of %d = %d", (*x)->key, newnode->key);
			printf("\nroot of %d = %d", newnode->key, root->key);
			return;
		}
	}	
}

void insert2(tp *x, tp *y)
{
	if((*y)->key < (*x)->key)
	{
		if((*x)->left != NULL)
		{
			insert2(&((*x)->left), &(*y));
		}
		else
		{	
			(*x)->left = *y;
			return;
		}
	}
	else if((*y)->key > (*x)->key)
	{
		if((*x)->right != NULL)
		{
			insert2(&((*x)->right), &(*y));
		}
		else
		{
			(*x)->right = *y;
			return;
		}
	}	
}

void delete(tp *x, int data)
{
	printf("\nx is pointig %d", (*x)->key);
	if((*x == root) && ((*x)->key == data))//Čĺëů íá äéáăńářů ôç ńßćá
	{
		if(((*x)->right == NULL) && ((*x)->left == NULL))//×ůńéň đáéäéá
		{
			printf("\n1D");
			free(*x);
			*x = NULL;
			printf("\nTree is empty!");
			return;			
		}
		else if(((*x)->right == NULL) && ((*x)->left != NULL))//Ěďíď áńéóôĺńü đáéäé
		{
			printf("\n2D");
			tp temp = *x;
			*x = (*x)->left;
			free(temp);
			temp = NULL;
			return;
		}
		else if(((*x)->right != NULL) && ((*x)->left == NULL))//Ěďíď äĺîé đáéäé
		{
			printf("\n3D");
			tp temp = *x;
			*x = (*x)->right;
			free(temp);
			temp = NULL;
			return;
		}
		else if(((*x)->right != NULL) && ((*x)->left != NULL))//ĺ÷ĺé 2 đáéäéá
		{
			printf("\n4D");
			tp right = (*x)->right;
			tp left = (*x)->left;
			free(*x);
			*x = NULL;
			*x = right;
			insert2(&right, &left);
			return;
		}
	}
	else if((*x == root) && ((*x)->key != data))
	{ 
		if(((*x)->key > data) && ((*x)->left!=NULL) && ((*x)->left->key != data))
			delete(&(*x)->left, data);
		else if(((*x)->key > data) && ((*x)->left!=NULL) && ((*x)->left->key == data))//Čĺëů íá äéáăńářů ôď áńéóôĺńü đáéäé ôçň ńßćáň
		{
			tp temp = (*x)->left;
			if((temp->left == NULL) && (temp->right == NULL))//×ůńéň đáéäéá
			{
				printf("\n5D");
				(*x)->left = NULL;
				free(temp);
				temp = NULL;
				return;
			}
			if((temp->left != NULL) && (temp->right == NULL))//Ěďíď áńéóôĺńü đáéäé
			{
				printf("\n6D");
				(*x)->left = temp->left;
				free(temp);
				temp = NULL;
				return;
			}
			if((temp->left == NULL) && (temp->right != NULL))//Ěďíď äĺîé đáéäé
			{
				printf("\n7D");
				(*x)->left = temp->right;
				free(temp);
				temp = NULL;
				return;
			}
			if((temp->left != NULL) && (temp->right != NULL))//ĺ÷ĺé 2 đáéäéá
			{
				printf("\n8D");
				tp right = temp->right;
				tp left = temp->left;
				(*x)->left = NULL;
				free(temp);
				temp = NULL;
				insert2(&(*x), &left);
				insert2(&(*x), &right);
				return;
			}
		}
		else if(((*x)->key < data) && ((*x)->right!=NULL) && ((*x)->right->key != data))
			delete(&(*x)->right, data);
		else if(((*x)->key < data) && ((*x)->right!=NULL) && ((*x)->right->key == data))//Čĺëů íá äéáăńářů ôď äĺîé đáéäé ôçň ńßćáň
		{
			tp temp = (*x)->right;
			if((temp->left == NULL) && (temp->right == NULL))//×ůńéň đáéäéá
			{
				printf("\n9D");
				(*x)->right = NULL;
				free(temp);
				temp = NULL;
				return;
			}
			if((temp->left != NULL) && (temp->right == NULL))//Ěďíď áńéóôĺńü đáéäé
			{
				printf("\n10D");
				(*x)->right = temp->left;
				free(temp);
				temp = NULL;
				return;
			}
			if((temp->left == NULL) && (temp->right != NULL))//Ěďíď äĺîé đáéäé
			{
				printf("\n11D");
				(*x)->right = temp->right;
				free(temp);
				temp = NULL;
				return;
			}
			if((temp->left != NULL) && (temp->right != NULL))//ĺ÷ĺé 2 đáéäéá
			{
				printf("\n12D");
				tp right = temp->right;
				tp left = temp->left;
				(*x)->right = NULL;
				free(temp);
				temp = NULL;
				insert2(&(*x), &left);
				insert2(&(*x), &right);
				return;
			}
		}	
	}
	else if((*x != root) && ((*x)->key != data))
	{
		if(((*x)->key > data) && ((*x)->left!=NULL) && ((*x)->left->key != data))
			delete(&(*x)->left, data);
		else if(((*x)->key > data) && ((*x)->left!=NULL) && ((*x)->left->key == data))//Čĺëů íá äéáăńářů ôď áńéóôĺńü đáéäé.
		{
			tp temp = (*x)->left;
			if((temp->left == NULL) && (temp->right == NULL))//×ůńéň đáéäéá
			{
				printf("\n13D");
				(*x)->left = NULL;
				free(temp);
				temp = NULL;
				return;
			}
			if((temp->left != NULL) && (temp->right == NULL))//Ěďíď áńéóôĺńü đáéäé
			{
				printf("\n14D");
				(*x)->left = temp->left;
				free(temp);
				temp = NULL;
				return;
			}
			if((temp->left == NULL) && (temp->right != NULL))//Ěďíď äĺîé đáéäé
			{
				printf("\n15D");
				(*x)->left = temp->right;
				free(temp);
				temp = NULL;
				return;
			}
			if((temp->left != NULL) && (temp->right != NULL))//ĺ÷ĺé 2 đáéäéá
			{
				printf("\n16D");
				tp right = temp->right;
				tp left = temp->left;
				(*x)->left = NULL;
				free(temp);
				temp = NULL;
				insert2(&root, &left);
				insert2(&root, &right);
				return;
			}
		}
		else if(((*x)->key < data) && ((*x)->right!=NULL) && ((*x)->right->key != data))
			delete(&(*x)->right, data);
		else if(((*x)->key < data) && ((*x)->right!=NULL) && ((*x)->right->key == data))//Čĺëů íá äéáăńářů ôď äĺîß đáéäé.
		{
			tp temp = (*x)->right;
			if((temp->left == NULL) && (temp->right == NULL))//×ůńéň đáéäéá
			{
				printf("\n17D");
				(*x)->right = NULL;
				free(temp);
				temp = NULL;
				return;
			}
			if((temp->left != NULL) && (temp->right == NULL))//Ěďíď áńéóôĺńü đáéäé
			{
				printf("\n18D");
				(*x)->right = temp->left;
				free(temp);
				temp = NULL;
				return;
			}
			if((temp->left == NULL) && (temp->right != NULL))//Ěďíď äĺîé đáéäé
			{
				printf("\n19D");
				(*x)->right = temp->right;
				free(temp);
				temp = NULL;
				return;
			}
			if((temp->left != NULL) && (temp->right != NULL))//ĺ÷ĺé 2 đáéäéá
			{
				printf("\n20D");
				tp right = temp->right;
				tp left = temp->left;
				(*x)->right = NULL;
				free(temp);
				temp = NULL;
				insert2(&root, &left);
				insert2(&root, &right);
				return;
			}
		}
	}
}
tp findmin(tp x)
{
	if(x->left != NULL)
		findmin(x->left);
	else
		return x;
}
tp findmax(tp x)
{
	if(x->right != NULL)
		findmin(x->right);
	else
		return x;
}

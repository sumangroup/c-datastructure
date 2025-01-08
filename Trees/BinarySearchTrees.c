#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *left;
	int data;
	struct node *right;
} *root = NULL;

void insert(int key)
{
	struct node *temp = root, *prev, *ptr;
	ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = key;
	ptr->left = NULL;
	ptr->right = NULL;

	if (root == NULL)
	{
		root = ptr;
		return;
	}
	else
	{
		while (temp != NULL)
		{
			prev = temp;
			if (key < temp->data)
				temp = temp->left;
			else
				temp = temp->right;
		}
	}

	if (key < prev->data)
		prev->left = ptr;
	else
		prev->right = ptr;
	return;
}

struct node *deleteNode(struct node *root, int key)
{
	if (root == NULL)
		return root;

	// Traverse the tree
	if (key < root->data)
	{
		root->left = deleteNode(root->left, key);
	}
	else if (key > root->data)
	{
		root->right = deleteNode(root->right, key);
	}
	else
	{
		// Node found
		// Case 1: No child or one child
		if (root->left == NULL)
		{
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			struct node *temp = root->left;
			free(root);
			return temp;
		}
		// Case 2: Node with two children
		// Find the inorder successor directly here
		struct node *temp = root->right;
		while (temp && temp->left != NULL)
		{
			temp = temp->left;
		}

		// Copy the inorder successor's data to this node
		root->data = temp->data;

		// Delete the inorder successor
		root->right = deleteNode(root->right, temp->data);
	}
	return root;
}

void inorder(struct node *root)
{
	struct node *temp = root;

	if (temp != NULL)
	{
		inorder(temp->left);
		printf("%d\t", temp->data);
		inorder(temp->right);
	}
}

void preorder(struct node *root)
{
	struct node *temp = root;

	if (temp != NULL)
	{
		printf("%d\t", temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
	return;
}

void postorder(struct node *root)
{
	struct node *temp = root;

	if (temp != NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("%d\t", temp->data);
	}

	return;
}

int main()
{
	int key, ch;
	do
	{
		printf("\n1.Insert a node \n2.Preorder \n3.Postorder \n4.Inorder \n5.delete\n 6.exit\n");
		printf("\nEnter choice: ");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
			printf("\nEnter the value to be inserted : ");
			scanf("%d", &key);
			insert(key);
			break;

		case 2:
			preorder(root);
			break;

		case 3:
			postorder(root);
			break;

		case 4:
			inorder(root);
			break;

		case 5:
			printf("Enter the value to delete: ");
			scanf("%d", &key);
			root = deleteNode(root, key);
			if (root != NULL)
			{
				printf("Deleted %d from the BST.\n", key);
			}
			else
			{
				printf("key %d not found.\n", key);
			}

			break;

		case 6:
			printf("Exiting.");
			break;

		default:
			printf("Invalid Choice");
		}
	} while (ch != 6);
	return 0;
}

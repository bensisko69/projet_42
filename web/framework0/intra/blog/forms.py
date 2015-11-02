from django import forms

from .models import Post, User, NewUser, Contact

class PostForm(forms.ModelForm):
	class Meta:
		model = Post
		fields = ('title', 'text',)

class ModelUser(forms.ModelForm):
	class Meta:
		model = User
		fields = ('username', 'password',)

class ModelNewUser(forms.ModelForm):
	password = forms.CharField(widget=forms.PasswordInput())
	class Meta:
		model = NewUser
		fields = ('username', 'firstname', 'lastname', 'email', 'password',)

class ModelContact(forms.ModelForm):
	class Meta:
		model = Contact
		fields = ('username', 'obj', 'text',)

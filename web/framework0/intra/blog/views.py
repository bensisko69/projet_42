from django.shortcuts import render, get_object_or_404, redirect
from django.utils import timezone
from .models import Post
from .forms import PostForm, ModelUser, ModelNewUser, ModelContact
from django.contrib.auth import logout, authenticate, login
from django.contrib.auth.models import User
from django.core.mail import send_mail

def post_index(request):
	return render(request, 'blog/index.html',)

def post_list(request):
	if request.user.is_authenticated():
		posts = Post.objects.filter(published_date__lte=timezone.now()).order_by('-published_date')
		return render(request, 'blog/post_list.html', {'posts': posts})
	return render(request, 'blog/register.html', {'form' : ModelUser})

def post_detail(request, pk):
	if request.user.is_authenticated():
		post = get_object_or_404(Post, pk=pk)
		return render(request, 'blog/post_detail.html', {'post': post})
	return render(request, 'blog/register.html', {'form' : ModelUser})

def post_new(request):
	if request.user.is_authenticated():
		if request.method == "POST":
			form = PostForm(request.POST)
			if form.is_valid():
				post = form.save(commit=False)
				post.author = request.user
				post.publish()
				post.save()
				return redirect('blog.views.post_detail', pk=post.pk)
		else:
			form = PostForm()
		return render(request, 'blog/post_edit.html', {'form': form})
	return render(request, 'blog/register.html', {'form' : ModelUser})

def post_edit(request, pk):
	if request.user.is_authenticated():
		post = get_object_or_404(Post, pk=pk)
		if request.method == "POST":
			form = PostForm(request.POST, instance=post)
			if form.is_valid():
				post = form.save(commit=False)
				post.author = request.user
				post.save()
				return redirect('blog.views.post_detail', pk=post.pk)
		else:
			form = PostForm(instance=post)
		return render(request, 'blog/post_edit.html', {'form': form})
	return render(request, 'blog/register.html', {'form' : ModelUser})

def post_logout(request):
	if request.user.is_authenticated():
		logout(request)
	return render(request, 'blog/register.html', {'form' : ModelUser})

def register(request):
	return render(request, 'blog/register.html', {'form' : ModelUser})

def register_user(request):
	if request.method == "POST":
		form = ModelUser(request.POST)
		if form.is_valid():
			username = request.POST['username']
			password = request.POST['password']
			user = authenticate(username=username, password=password)
			if user is not None:
				if user.is_active:
					login(request, user)
					return redirect('blog.views.post_new')
			else:
				form = ModelUser()
	return render(request, 'blog/register.html', {'form' : ModelUser, 'fail' : 'Please enter the identify valid.'})

def registration(request):
		return render(request, 'blog/registration.html', {'form' : ModelNewUser})

def registration_user(request):
	if request.method == "POST":
		form = ModelNewUser(request.POST)
		if form.is_valid():
			try:
				ret = User.objects.get(username=request.POST['username'])
			except User.DoesNotExist:
				user = User.objects.create_user(request.POST['username'],request.POST['email'], request.POST['password'])
				user.first_name = request.POST['firstname']
				user.last_name = request.POST['lastname']
				send_mail('Welcome, '+request.POST['username'], 'Thanks for your registration', 'The blog of python', [request.POST['email'], 'loicrg69@gmail.com'], fail_silently=False)
				user.save()
				return render(request, 'blog/register.html', {'form' : ModelUser})
			return render(request, 'blog/registration.html', {'form' : ModelNewUser, 'fail' : 'Username already taken'})
	return render(request, 'blog/registration.html', {'form' : ModelNewUser, 'fail' : 'Thanks to fill in all fields '})

def contact(request):
	return render(request, 'blog/contact.html', {'form' : ModelContact})

def send_contact(request):
	if request.method == "POST":
		form = ModelContact(request.POST)
		if form.is_valid():
			contact = form.save(commit=False)
			contact.save()
			return render(request, 'blog/index.html')
	return render(request, 'blog/contact.html', {'form' : ModelContact})


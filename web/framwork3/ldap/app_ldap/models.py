from django.db import models

class User_ldap(models.Model):
	Username = models.CharField(max_length=200)
	Name = models.CharField(max_length=200)
	FirstName = models.CharField(max_length=200)
	Email = models.EmailField()
	Phone = models.IntegerField(default=0)
	Date = models.DateTimeField('date')
	def __str__(self):
		return self.Username
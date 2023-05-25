import bcrypt

a = '1234'
print(bcrypt.hashpw(a.encode('utf-8'), bcrypt.gensalt(10)))
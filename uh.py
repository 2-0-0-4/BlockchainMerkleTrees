
#varying size ----------------------------
l = 2 # lambda
size  = 100 # Number of trials
X = np.random.poisson(l,size=size)
plt.title("Poisson RV; keeping p,n constant (lambda=%i size= %i)"%(l,size))
plt.hist(X,bins='auto',rwidth = 0.3)
plt.show()

l = 2 # lambda
size  = 1000 # Number of trials
X = np.random.poisson(l,size=size)
plt.title("Poisson RV; keeping p,n constant (lambda=%i size= %i)"%(l,size))
plt.hist(X,bins='auto',rwidth = 0.3)
plt.show()

l = 2 # lambda
size  = 10000 # Number of trials
X = np.random.poisson(l,size=size)
plt.title("Poisson RV; keeping p,n constant (lambda=%i size= %i)"%(l,size))
plt.hist(X,bins='auto',rwidth = 0.3)
plt.show()


l = 2 # lambda
size  = 1000000 # Number of trials
X = np.random.poisson(l,size=size)
plt.title("Poisson RV; keeping p,n constant (lambda=%i size= %i)"%(l,size))
plt.hist(X,bins='auto',rwidth = 0.3)
plt.show()

#VARYING lambda: --------------------------------------
l = 2 # lambda
size  = 100 # Number of trials
X = np.random.poisson(l,size=size)
plt.title("Poisson RV; keeping size constant (lambda=%i size= %i)"%(l,size))
plt.hist(X,bins='auto',rwidth = 0.3)
plt.show()

l = 3 # lambda
size  = 100 # Number of trials
X = np.random.poisson(l,size=size)
plt.title("Poisson RV; keeping size constant (lambda=%i size= %i)"%(l,size))
plt.hist(X,bins='auto',rwidth = 0.3)
plt.show()

l = 4 # lambda
size  = 100 # Number of trials
X = np.random.poisson(l,size=size)
plt.title("Poisson RV; keeping size constant (lambda=%i size= %i)"%(l,size))
plt.hist(X,bins='auto',rwidth = 0.3)
plt.show()

l = 5 # lambda
size  = 100 # Number of trials
X = np.random.poisson(l,size=size)
plt.title("Poisson RV; keeping size constant (lambda=%i size= %i)"%(l,size))
plt.hist(X,bins='auto',rwidth = 0.3)
plt.show()

# #varying num of states-------------------------------------------

# l = 2 # lambda
# size  = 100 # Number of trials
# X = np.random.poisson(l,size=size)
# plt.title("Poisson RV; keeping size,p constanlambda (i.2f size= %i)l%(p,size))
# plt.hist(X,bins='auto',rwidth = 0.3)
# plt.show()

# l = 2 # lambda
# size  = 100 # Number of trials
# X = np.random.poisson(l,size=size)
# plt.title("Poisson RV; keeping size,p constanlambda (i.2f size= %i)l%(p,size))
# plt.hist(X,bins='auto',rwidth = 0.3)
# plt.show()

# l = 2 # lambda
# size  = 100 # Number of trials
# X = np.random.poisson(l,size=size)
# plt.title("Poisson RV; keeping size,p constanlambda (i.2f size= %i)l%(p,size))
# plt.hist(X,bins='auto',rwidth = 0.3)
# plt.show()

# l = 2 # lambda
# size  = 100 # Number of trials
# X = np.random.poisson(l,size=size)
# plt.title("Poisson RV; keeping size,p constanlambda (i.2f size= %i)l%(p,size))
# plt.hist(X,bins='auto',rwidth = 0.3)
# plt.show()

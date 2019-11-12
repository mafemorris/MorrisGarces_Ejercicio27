primer_grado.png : ode.py odeEuler.txt
	python ode.py

odeEuler.txt : ode.x
	./ode.x

ode.x : ode.cpp
	c++ ode.cpp -o ode.x

clear :
	rm ode.x odeEuler.txt odeImplicita.txt graficas.png
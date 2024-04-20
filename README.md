# TP2_2024_Gramajo
Cuando se configura el GPIO del led como
GPIO_OType_OD el led deja de funcionar.
Es decir, no destella como lo hacia 
cuando estaba configurado como
GPIO_OType_PP.
Esto se debe a que es de salida Open Drain
por lo cual queda configurado como circuito 
abierto y se debe realizar el conexionado
para cerrarlo, como por ejemplo una resistencia
pull_down o pull_up.

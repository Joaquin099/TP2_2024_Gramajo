# TP2_2024_Gramajo
Cuando se configura el GPIO del led como GPIO_OType_OD el led deja de funcionar.
Es decir, no destella como lo hacia cuando estaba configurado como GPIO_OType_PP.
Esto se debe a que es de salida Open Drain por lo cual queda configurado como circuito 
abierto y se debe realizar el conexionado para cerrarlo, como por ejemplo una resistencia
pull_down o pull_up.

La diferencia que pude observar con respecto al ejercicio numero 2 es que en ciertos pulsos 
el osciloscopio detecta rebotes a la hora de accionar el pulsador externo. Este efecto
puede ser causa de las conexiones, ya que uno se encuentra integrado a la placa y puede
obtener ciertos filtros que eliminen ruido o lecturas incorrectas. En cambio, el pulsador
externo solo se encuentra conectado con cables y sin ningun filtro.
Una observacion, es que se dificulto a la hora de encontrar el rebote ya que se obtenia 
una respuesta similar al pulsador del micro.


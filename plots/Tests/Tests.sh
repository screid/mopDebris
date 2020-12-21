dir="Experimentos"
outAll="Out.txt"
salida="salida.txt"
out="Solucion.txt"
paretoFront="PF.txt"

rm -rf ${outAll} ${salida} ${out} ${paretoFront}


itExt=1000
itInt=1000
T = 100
alpha = 0.9
params="${itExt} ${itInt} ${T} ${alpha}"

#instanceList="Instancia1_N10_K2_D2_Depot1.txt Instancia2_N10_K1_D3_Depot1.txt Instancia3_N10_K2_D2_Depot1.txt Instancia4_N10_K1_D2_Depot2.txt Instancia5_N10_K1_D3_Depot2.txt Instancia6_N10_K1_D2_Depot2.txt Instancia7_N10_K2_D1_Depot3.txt Instancia8_N10_K1_D2_Depot3.txt Instancia9_N10_K1_D2_Depot3.txt Instancia10_N10_K1_D3_Depot4.txt Instancia11_N10_K1_D2_Depot4.txt Instancia12_N10_K2_D1_Depot4.txt Instancia13_N20_K2_D2_Depot1.txt Instancia14_N20_K1_D4_Depot1.txt Instancia15_N20_K1_D4_Depot1.txt Instancia16_N20_K1_D3_Depot2.txt Instancia17_N20_K3_D1_Depot2.txt Instancia18_N20_K2_D1_Depot2.txt Instancia19_N20_K1_D2_Depot3.txt Instancia20_N20_K3_D1_Depot3.txt Instancia21_N20_K1_D3_Depot3.txt Instancia22_N20_K1_D3_Depot4.txt Instancia23_N20_K3_D1_Depot4.txt Instancia24_N20_K3_D1_Depot4.txt Instancia25_N30_K3_D1_Depot1.txt Instancia26_N30_K1_D5_Depot1.txt Instancia27_N30_K3_D1_Depot1.txt Instancia28_N30_K3_D1_Depot2.txt Instancia29_N30_K2_D2_Depot2.txt Instancia30_N30_K1_D3_Depot2.txt Instancia31_N30_K1_D3_Depot3.txt Instancia32_N30_K1_D4_Depot3.txt Instancia33_N30_K3_D1_Depot3.txt Instancia34_N30_K1_D4_Depot4.txt Instancia35_N30_K2_D2_Depot4.txt Instancia36_N30_K2_D2_Depot4.txt Instancia37_N45_K1_D5_Depot1.txt Instancia38_N45_K3_D1_Depot1.txt Instancia39_N45_K1_D5_Depot1.txt Instancia40_N45_K3_D1_Depot2.txt Instancia41_N45_K2_D2_Depot2.txt Instancia42_N45_K3_D1_Depot2.txt Instancia43_N45_K3_D1_Depot3.txt Instancia44_N45_K1_D4_Depot3.txt Instancia45_N45_K1_D3_Depot3.txt Instancia46_N45_K3_D1_Depot4.txt Instancia47_N45_K3_D1_Depot4.txt Instancia48_N45_K3_D1_Depot4.txt Instancia49_N55_K1_D6_Depot1.txt Instancia50_N55_K2_D3_Depot1.txt Instancia51_N55_K1_D6_Depot1.txt Instancia52_N55_K3_D1_Depot2.txt Instancia53_N55_K3_D1_Depot2.txt Instancia54_N55_K1_D4_Depot2.txt Instancia55_N55_K3_D1_Depot3.txt Instancia56_N55_K1_D4_Depot3.txt Instancia57_N55_K3_D1_Depot3.txt Instancia58_N55_K1_D5_Depot4.txt Instancia59_N55_K2_D2_Depot4.txt Instancia60_N55_K3_D1_Depot4.txt Instancia61_N65_K3_D2_Depot1.txt Instancia62_N65_K2_D3_Depot1.txt Instancia63_N65_K2_D3_Depot1.txt Instancia64_N65_K2_D2_Depot2.txt Instancia65_N65_K3_D1_Depot2.txt Instancia66_N65_K2_D2_Depot2.txt Instancia67_N65_K2_D2_Depot3.txt Instancia68_N65_K2_D2_Depot3.txt Instancia69_N65_K1_D5_Depot3.txt Instancia70_N65_K1_D6_Depot4.txt Instancia71_N65_K3_D2_Depot4.txt Instancia72_N65_K1_D6_Depot4.txt Instancia73_N75_K1_D8_Depot1.txt Instancia74_N75_K3_D2_Depot1.txt Instancia75_N75_K2_D4_Depot1.txt Instancia76_N75_K3_D2_Depot2.txt Instancia77_N75_K2_D3_Depot2.txt Instancia78_N75_K2_D3_Depot2.txt Instancia79_N75_K3_D2_Depot3.txt Instancia80_N75_K2_D3_Depot3.txt Instancia81_N75_K2_D3_Depot3.txt Instancia82_N75_K3_D2_Depot4.txt Instancia83_N75_K1_D7_Depot4.txt Instancia84_N75_K1_D7_Depot4.txt Instancia85_N82_K3_D3_Depot1.txt Instancia86_N82_K2_D4_Depot1.txt Instancia87_N82_K1_D9_Depot1.txt Instancia88_N82_K2_D3_Depot2.txt Instancia89_N82_K1_D7_Depot2.txt Instancia90_N82_K2_D3_Depot2.txt Instancia91_N82_K2_D3_Depot3.txt Instancia92_N82_K1_D6_Depot3.txt Instancia93_N82_K3_D2_Depot3.txt Instancia94_N82_K1_D8_Depot4.txt Instancia95_N82_K3_D2_Depot4.txt Instancia96_N82_K3_D2_Depot4.txt"

instanceList="Instancia1_N10_K2_D2_Depot1.txt Instancia24_N20_K3_D1_Depot4.txt Instancia36_N30_K2_D2_Depot4.txt Instancia48_N45_K3_D1_Depot4.txt Instancia60_N55_K3_D1_Depot4.txt Instancia72_N65_K1_D6_Depot4.txt Instancia73_N75_K1_D8_Depot1.txt Instancia85_N82_K3_D3_Depot1.txt"

seedList="129 137 279 672 195 666 429 762 821 483 999 729 318 349 287 241 476 555 581 573"

for instance in ${instanceList}; do
    echo "Ejecutando instancia: ${instance}" 
    
    #Busca puntos de referencia en el archivo respectivo
    #exec<"puntosDeReferencia.dat"
    
    #while read line
    #do
#         echo "@line" 
    #    set -- $line
    #    name=$1
    #    if [[ ${instance} == ${name} ]]; 
    #    then
    #        puntosReferencia=${line#* }
    #        echo "nombre: ${name}, puntosReferencia: ${puntosReferencia}" 
    #    fi
    #done
    #Puntos de referencia encontrados
    
    #Para cada semilla
  for seed in ${seedList}; do
	  rm -rf ${paretoFront}

	  #Ejecutar MOPK 
   	echo "./MOPDebris ${dir}/${instance} ${seed} ${params}"
   	./MOPDebris ${dir}/${instance} ${seed} ${params}
    
    	#Agregar los # al frente para cálculo de hv
    echo "#" >> ${paretoFront}
    cat ${out} >> ${paretoFront}
    echo "#" >> ${paretoFront}
 
	  #Calcular los hv
    #echo "./wfg ${paretoFront} ${puntosReferencia} > ${salida}"
    #./wfg ${paretoFront} ${puntosReferencia} > ${salida}  

    #quality=`tail -3 ${salida} |head -1 |awk -F ' = ' '{print $2}'`

    #echo "${instance} ${seed} ${quality}" >> ${outAll}
    echo "${instance} ${seed}" >> ${outAll}
  done
done

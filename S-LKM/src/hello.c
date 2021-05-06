#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ivan Valero");
MODULE_DESCRIPTION("Un LKM para PDIH");
MODULE_VERSION("0.0.1");

static char *nombre = "Mundo";
module_param(nombre,charp,S_IRUGO);
MODULE_PARM_DESC(nombre, "Lo que va detrás de Hola");

static int __init saludar(void){
    printk(KERN_INFO "[INICIO] Iniciando el módulo de prueba");
    printk(KERN_ALERT "[INICIO] Hola %s desde los logs :)", nombre);
    return 0;
}

static void __exit despedirse(void){
    printk(KERN_ALERT "[INICIO] Adiós %s desde los logs :(", nombre);
}

module_init(saludar);
module_exit(despedirse);
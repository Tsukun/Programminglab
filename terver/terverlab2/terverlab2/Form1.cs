using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace terverlab2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        void func()
        {
            Random rand = new Random();
            double lyambd;
            double Tn = 100;
            double[] average = new double[0] ;
            double tay;
            double t=0;
            double dimension=0;
            int N = 0;
            int countcycle;
            countcycle = int.Parse(textBox2.Text);
            lyambd = double.Parse(textBox1.Text);
            for (int i = 0; i < countcycle; i++)
            {
                double[] mas = new double[0];
                while (t <= Tn)
                {

                    Array.Resize(ref mas, mas.Length + 1);
                    double r = rand.NextDouble();
                    tay = -1 / lyambd * Math.Log(r);
                    t += tay;
                    mas[N] = t;
                    N++;

                }
                    if(mas.Length!=0)
                    Array.Resize(ref average, mas.Length);

                    for (int j = 0; j < mas.Length; j++)
                        average[j] += mas[j];
                    dimension += mas.Length;

            }

            for(int i=0;i<Math.Floor(dimension/countcycle);i++)
            chart1.Series[0].Points.AddXY(average[i]/countcycle,i);
        }
        private void button1_Click(object sender, EventArgs e)
        {
            chart1.Series[0].Points.Clear();
            func();
        }

 
    }
}

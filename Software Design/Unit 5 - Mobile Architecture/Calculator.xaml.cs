/*
 * Vincent Latona
 */

using System.Runtime.CompilerServices;

namespace IdealWeightCalculator.Views;

public partial class Calculator : ContentPage
{
	public Calculator()
	{
		InitializeComponent();
		BindingContext = new IdealWeightCalculator.ViewModels.CalcViewModel(); //Bind to VM
	}
}
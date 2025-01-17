#pragma once

#include "Ange/Core/Primitives.h"
#include "Ange/Core/Font.h"
#include <array>

namespace Ange {

	//------------------------------------------------------------------------------------------------------
	//Classes
	//------------------------------------------------------------------------------------------------------

	/*!
	The basic structure describing the appearance of a rectangular space.
	*/
	struct RectTheme
	{
		/* Default constructor. */
		RectTheme(
			Color tint = Color(255,255,255,255),
			Color borderColor = Color(128,128,128,255)
		){
			Tint = tint;
			BorderColor = borderColor;
		}

		/* Background color. */
		Color Tint;

		/* Border color. */
		Color BorderColor;
	};

	//----------------------------------------------------------------------------------


	/*!
	Contains basic information about the colors of the Background widget.
	*/
	struct BackgroundTheme
	{
		/* Default constructor. */
		BackgroundTheme(
			Color tint = Color(255,255,255,255),
			Color borderColor = Color(128,128,128,255),
			Dimension<int> borderSize = Dimension<int>(1,1),
			std::array<float, 4> radiuses = {0.0f, 0.0f, 0.0f, 0.0f}
		){
			Base.Tint = tint;
			Base.BorderColor = borderColor;
			BorderSize = borderSize;
			Radiuses = radiuses;
		}

		/* Background & Border color. */
		RectTheme Base;
	
		/* Border size in both direction (X and Y). */
		Dimension<int> BorderSize;

		/* Radiuses of the corners of the rectangle. */
		std::array<float, 4> Radiuses;
	};

	//----------------------------------------------------------------------------------

	/*!
	Contains basic information about the Image widget theme.
	*/
	struct ImageTheme
	{
		/* Default constructor. */
		ImageTheme(
			Color tint = Color(255, 255, 255, 255),
			Color borderColor = Color(0, 0, 0, 0),
			Dimension<int> borderSize = Dimension<int>(0, 0)
		){
			Base.Tint = tint;
			Base.BorderColor = borderColor;
			BorderSize = borderSize;
		}

		/* Image tint & Border color. */
		RectTheme Base;

		/* Border size in both direction (X and Y). */
		Dimension<int> BorderSize;
	};

	//----------------------------------------------------------------------------------

	/*!
	Contains basic information about the Text widget theme.
	*/
	struct TextTheme
	{
		/* Default constructor. */
		TextTheme(
			int size = 12,
			Color tint = Color(255,255,255, 255),
			Font* fnt = nullptr
		){
			iFontSize = size;
			Tint = tint;
			UsedFont = fnt;
		}

		/* Destructor - does not delete "UsedFont". Please cleanup by yourself. */
		~TextTheme()
		{
		}

		/* Describes font size. */
		int iFontSize;

		/* Describes font color. */
		Color Tint;

		/* Pointer to the loaded Font. */
		Font* UsedFont;
	};

	//----------------------------------------------------------------------------------

	/*!
	Contains basic information about the SimpleButton widget theme.
	*/
	struct SimpleButtonTheme
	{
		/* Default constructor. */
		SimpleButtonTheme(
			RectTheme normalColor = RectTheme(),
			RectTheme hoverColor = RectTheme(),
			RectTheme activeColor = RectTheme(),
			Dimension<int> borderSize = Dimension<int>(1,1),
			TextTheme textTheme = TextTheme(),
			std::array<float, 4> radiuses = { 10.0f, 10.0f, 10.0f, 10.0f }
		){
			Base[0] = normalColor;
			Base[1] = hoverColor;
			Base[2] = activeColor;
			BorderSize = borderSize;
			TextTh = textTheme;
			Radiuses = radiuses;
		}

		/* Button tint & border color. [0 - Normal, 1 - Hover, 2 - Active] */
		RectTheme Base[3];
		
		/* Border size in both direction (X and Y). */
		Dimension<int> BorderSize;

		/* Button text theme. */
		TextTheme TextTh;

		/* Radiuses of the corners of the Button. */
		std::array<float, 4> Radiuses;
	};

	//----------------------------------------------------------------------------------

	/*!
	Contains basic information about the SimpleInput widget theme.
	*/
	struct SimpleInputTheme
	{

		SimpleInputTheme(
			RectTheme normalColor = RectTheme(),
			RectTheme hoverColor = RectTheme(),
			RectTheme activeColor = RectTheme(),
			Dimension<int> borderSize = Dimension<int>(1, 1),
			TextTheme defaultTextTh = TextTheme(),
			TextTheme textTh = TextTheme(),
			Color selection = Color(128, 128, 128, 255),
			Color prompt = Color(255, 255, 255, 255),
			Color bar = Color(255, 255, 255, 255),
			Point<int> margins = Point<int>(0, 0),
			int barHeight = 2
		){
			Base[0] = normalColor;
			Base[1] = hoverColor;
			Base[2] = activeColor;
			BorderSize = borderSize;
			DefaultText = defaultTextTh;
			Text = textTh;
			Selection = selection;
			Prompt = prompt;
			Bar = bar;
			Margins = margins;
			iBarHeight = barHeight;
		}

		/* Button color & Border color. [0 - Normal, 1 - Hover, 2 - Active] */
		RectTheme Base[3];

		/* Border size in both direction (X and Y). */
		Dimension<int> BorderSize;

		/* Default text theme. */
		TextTheme DefaultText;

		/* Text theme. */
		TextTheme Text;

		/* Color of the text selection. */
		Color Selection;

		/* Color of the input prompt. */
		Color Prompt;

		/* Color of the input bottom bar.*/
		Color Bar;

		/* Text margins within widget. */
		Point<int> Margins;

		/* Bar height. */
		int iBarHeight;

	};

	//----------------------------------------------------------------------------------

	/*!
	Contains basic information about the VScroller widget theme.
	*/
	struct VScrollerTheme
	{

		VScrollerTheme(
			RectTheme backgroundColor = RectTheme(),
			RectTheme normalColor = RectTheme(),
			RectTheme hoverColor = RectTheme(),
			RectTheme activeColor = RectTheme(),
			Dimension<int> scrollerBorderSize = Dimension<int>(1, 1),
			Dimension<int> sliderBorderSize = Dimension<int>(1, 1),
			int sliderWidth = 18
		) {
			Base = backgroundColor;
			Slider[0] = normalColor;
			Slider[1] = hoverColor;
			Slider[2] = activeColor;
			iWidth = sliderWidth;
			BaseBorderSize = scrollerBorderSize;
			SliderBorderSize = sliderBorderSize;
		}

		/* Button color & border color for Widget background. */
		RectTheme Base;

		/* Button color & border color for Slider. [0 - Normal, 1 - Hover, 2 - Active] */
		RectTheme Slider[3];

		/* Widget border size in both direction (X and Y). */
		Dimension<int> BaseBorderSize;

		/* Slider border size in both direction (X and Y). */
		Dimension<int> SliderBorderSize;

		/* Scroller width height. */
		int iWidth;

	};

	//----------------------------------------------------------------------------------

	/*!
	Contains basic information about the ProgressBar widget theme.
	*/
	struct ProgressBarTheme
	{
		/* Default constructor. */
		ProgressBarTheme(
			BackgroundTheme background = BackgroundTheme(),
			BackgroundTheme fill = BackgroundTheme(),
			TextTheme textTheme = TextTheme()
		) {
			Base = background;
			Fill = fill;
			TextTh = textTheme;
		}

		/* Background color & border. */
		BackgroundTheme Base;

		/* Fill color & border. */
		BackgroundTheme Fill;

		/* ProgressBar info-text theme. */
		TextTheme TextTh;
	};

	//----------------------------------------------------------------------------------

	/*!
	Contains basic information about the ContextMenu widget theme.
	*/
	struct ContextMenuTheme
	{
		/* Default constructor. */
		ContextMenuTheme(
			BackgroundTheme background = BackgroundTheme(),
			SimpleButtonTheme item = SimpleButtonTheme(),
			ImageTheme image = ImageTheme(),
			int rowHeight = 20
		) {
			Base = background;
			Item = item;
			Img = image;
			iRow = rowHeight;
		}

		/* Background color & border. */
		BackgroundTheme Base;

		/* Item (buttons) theme. */
		SimpleButtonTheme Item;

		/* Image theme (for Item objects). */
		ImageTheme Img;

		/* Stores row height. */
		int iRow; 

	};

	//----------------------------------------------------------------------------------

	/*!
	Contains basic information about the Checkbox widget theme.
	*/
	struct CheckboxTheme
	{
		/* Default constructor. */
		CheckboxTheme(
			SimpleButtonTheme button = SimpleButtonTheme(),
			BackgroundTheme fill = BackgroundTheme(),
			Dimension<size_t> margin = {3,3}
		) {
			Base = button;
			Fill = fill;
			Margins = margin;
		}

		/* Background color & border. */
		SimpleButtonTheme Base;

		/* Fill color & border. */
		BackgroundTheme Fill;

		/* Defines 'size' of the fill rectangle. */
		Dimension<size_t> Margins;
	};

	//-------------------------------------------------------------------------------------------------------

	/*!
	Contains the themes for all basic widgets of the library.
	*/
	struct Theme
	{
		/*!
		Assigns a font to all sub-themes. Font is not deleted inside Theme descturctor.
		*/
		void AssignFontToAll(Font* font)
		{
			ContentText.UsedFont = Header1.UsedFont = Header2.UsedFont = Header3.UsedFont = font;
			SimpleButtonBG.TextTh.UsedFont = SimpleButtonIMG.TextTh.UsedFont = font;
			SimpleInput.Text.UsedFont = SimpleInput.DefaultText.UsedFont = font;
			ProgressBar.TextTh.UsedFont = ContextMenu.Item.TextTh.UsedFont = font;
		}

		BackgroundTheme Background;
		ImageTheme Image;
		TextTheme ContentText;
		TextTheme Header1;
		TextTheme Header2;
		TextTheme Header3;
		SimpleButtonTheme SimpleButtonBG;
		SimpleButtonTheme SimpleButtonIMG;
		SimpleInputTheme SimpleInput;
		VScrollerTheme VScroller;
		ProgressBarTheme ProgressBar;
		ContextMenuTheme ContextMenu;
		CheckboxTheme Checkbox;
	};

	/* Default ANGE widgets theme. Note: user have to load the fonts, in this case "Noto" font. */
	static const Theme DefTheme = {
		{	
			{242,245,250,255},
			{230,233,235,255},
			{1,1}
		},
		{ 
			{255,255,255,255},
			{0,0,0,0},
			{0,0}
		},
		{ 12, {0,0,0,255} },
		{ 24, {107,122,138,255} },
		{ 19, {107,122,138,255} },
		{ 15, {107,122,138,255} },
		{
			{{130,133,135,255}, {60,60,43,255}},
			{{77,79,80,255}, {26,30,33,255}},
			{{0x444042}, {0x2a192d}},
			{2,2},
			{15, {255,255,2555,255}}
		},
		{
			{{0x7b7478}, {0x4d2d52}},
			{{0xFFFFFF}, {0xFFFFFF}},
			{{0x444042}, {0x2a192d}},
			{0,0},
			{12, {0,0,0,255}}
		},
		{
			{{130,133,135,255}, {230,233,235,255}},
			{{77,79,80,255}, {26,30,33,255}},
			{{0x444042}, {0x2a192d}},
			{0,0},
			{12, {20,20,20,180}},
			{12, {255,255,255,255}},
			{128,128,128,255},
			{255,255,255,255},
			{26,30,33,255},
			{4,4},
			1
		},
		{
			{{241,241,241,255},{0,0,0,0}},
			{{193,193,193,255}, {0,0,0,0}},
			{{168,168,168,255}, {0,0,0,0}},
			{{120,120,120,255}, {0,0,0,0}},
			{0,0},
			{0,0},
			18
		},
		{
			{{255,255,255,255},{128,128,128,255}, {1,1}},
			{{100,100,255,255},{100,100,255,255}, {0,0}},
			{ 12, {0,0,0,255} }
		},
		{
			{{242,242,242,255},{100,100,255,255}, {1,1}},
			{
				{{242,242,242,255}, {242,242,242,255}},
				{{145,201,247,255}, {145,201,247,255}},
				{{145,201,247,255}, {145,201,247,255}},
				{1,1},
				{9, {0,0,0,255}}
			},
			{{255,255,255,255},{0,0,0,0}, {0,0}},
			20
		},
		{
			{
				{{242,242,242,255}, {0,0,0,255}},
				{{145,201,247,255}, {0,0,0,255}},
				{{145,201,247,255}, {0,0,0,255}},
				{1,1},
				{9, {0,0,0,255}}
			},
			{{0,0,0,255}, {230,233,235,255}, {1,1}},
			{2,2}
		}
	};

}
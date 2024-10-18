#include "includes.h"



//PLEASE READ ALL THE COMMENTS TO LEARN WHAT UR DOING :))
//WRITEN WITH LOVE BY Cl4vr and oxyxiy <3

//TO BE CLEAR OXYXIY JUST MADE A BURNER GITHUB ACCOUNT BECAUSE HE WANTS HIS IDENTITY SECRET 

//also All Comments are going to be Named For The Person Who Made Them :)




//basic shit doesnt need explaining
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

Present oPresent;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;





//-----------Cl4vr´s Code-----------
void InitImGui()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, pContext);

	// Replace Ur ImGui Style With The Current One
	ImGuiStyle& style = ImGui::GetStyle();

	// ImGui Style By "Modern made by LousyBook-01"
	// 
	//Just A Bit Modified By Me :>

	style.Alpha = 1.0f;
	style.WindowPadding = ImVec2(10.10000038146973f, 10.10000038146973f);
	style.WindowRounding = 10.30000019073486f;
	style.WindowBorderSize = 1.0f;
	style.WindowMinSize = ImVec2(20.0f, 32.0f);
	style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
	style.WindowMenuButtonPosition = ImGuiDir_Right;
	style.ChildRounding = 8.199999809265137f;
	style.ChildBorderSize = 1.0f;
	style.PopupRounding = 10.69999980926514f;
	style.PopupBorderSize = 1.0f;
	style.FramePadding = ImVec2(20.0f, 1.5f);
	style.FrameRounding = 4.800000190734863f;
	style.FrameBorderSize = 0.0f;
	style.ItemSpacing = ImVec2(9.699999809265137f, 5.300000190734863f);
	style.ItemInnerSpacing = ImVec2(5.400000095367432f, 9.300000190734863f);
	style.IndentSpacing = 10.69999980926514f;
	style.ColumnsMinSpacing = 6.0f;
	style.ScrollbarSize = 12.10000038146973f;
	style.ScrollbarRounding = 20.0f;
	style.GrabMinSize = 10.0f;
	style.GrabRounding = 4.599999904632568f;
	style.TabRounding = 4.0f;
	style.TabBorderSize = 0.0f;
	style.ColorButtonPosition = ImGuiDir_Right;
	style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
	style.SelectableTextAlign = ImVec2(0.0f, 0.0f);

	style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(1.0f, 1.0f, 1.0f, 0.3991416096687317f);
	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.03921568766236305f, 0.03921568766236305f, 0.03921568766236305f, 0.9399999976158142f);
	style.Colors[ImGuiCol_ChildBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
	style.Colors[ImGuiCol_PopupBg] = ImVec4(0.05098039284348488f, 0.05098039284348488f, 0.05098039284348488f, 0.9399999976158142f);
	style.Colors[ImGuiCol_Border] = ImVec4(0.4274509847164154f, 0.4274509847164154f, 0.4980392158031464f, 0.5f);
	style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
	style.Colors[ImGuiCol_FrameBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.4206008315086365f);
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.1411764770746231f, 0.1411764770746231f, 0.1411764770746231f, 0.4000000059604645f);
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.2313725501298904f, 0.2313725501298904f, 0.2313725501298904f, 0.8626609444618225f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.09411764889955521f, 0.09411764889955521f, 0.09411764889955521f, 1.0f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.0f, 0.0f, 0.0f, 0.2918455004692078f);
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.1372549086809158f, 0.1372549086809158f, 0.1372549086809158f, 1.0f);
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.01960784383118153f, 0.01960784383118153f, 0.01960784383118153f, 0.5299999713897705f);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.3098039329051971f, 0.3098039329051971f, 0.3098039329051971f, 1.0f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.407843142747879f, 0.407843142747879f, 0.407843142747879f, 1.0f);
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(1.0f, 0.2313725501298904f, 0.2313725501298904f, 1.0f);
	style.Colors[ImGuiCol_CheckMark] = ImVec4(0.9803921580314636f, 0.2588235437870026f, 0.2588235437870026f, 1.0f);
	style.Colors[ImGuiCol_SliderGrab] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(1.0f, 0.2313725501298904f, 0.2313725501298904f, 1.0f);
	style.Colors[ImGuiCol_Button] = ImVec4(0.0f, 0.0f, 0.0f, 0.5793991088867188f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.09803921729326248f, 0.09803921729326248f, 0.09803921729326248f, 1.0f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(1.0f, 0.2313725501298904f, 0.2313725501298904f, 1.0f);
	style.Colors[ImGuiCol_Header] = ImVec4(0.0f, 0.0f, 0.0f, 0.454935610294342f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.1803921610116959f, 0.1803921610116959f, 0.1803921610116959f, 0.800000011920929f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.2313725501298904f, 0.2313725501298904f, 0.2313725501298904f, 0.8626609444618225f);
	style.Colors[ImGuiCol_Separator] = ImVec4(0.0f, 0.0f, 0.0f, 0.5f);
	style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.09803921729326248f, 0.4000000059604645f, 0.7490196228027344f, 0.7799999713897705f);
	style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.09803921729326248f, 0.4000000059604645f, 0.7490196228027344f, 1.0f);
	style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.2588235437870026f, 0.5882353186607361f, 0.9764705896377563f, 0.2000000029802322f);
	style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.2588235437870026f, 0.5882353186607361f, 0.9764705896377563f, 0.6700000166893005f);
	style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.2588235437870026f, 0.5882353186607361f, 0.9764705896377563f, 0.949999988079071f);
	style.Colors[ImGuiCol_Tab] = ImVec4(0.105882354080677f, 0.105882354080677f, 0.105882354080677f, 1.0f);
	style.Colors[ImGuiCol_TabHovered] = ImVec4(1.0f, 0.364705890417099f, 0.6745098233222961f, 0.800000011920929f);
	style.Colors[ImGuiCol_TabActive] = ImVec4(1.0f, 0.2235294133424759f, 0.2235294133424759f, 1.0f);
	style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.1098039224743843f, 0.168627455830574f, 0.239215686917305f, 0.9724000096321106f);
	style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.1333333402872086f, 0.2588235437870026f, 0.4235294163227081f, 1.0f);
	style.Colors[ImGuiCol_PlotLines] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
	style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.0f, 0.4274509847164154f, 0.3490196168422699f, 1.0f);
	style.Colors[ImGuiCol_PlotHistogram] = ImVec4(1.0f, 0.2156862765550613f, 0.2156862765550613f, 1.0f);
	style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.0f, 0.2156862765550613f, 0.6980392336845398f, 1.0f);
	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.9764705896377563f, 0.2588235437870026f, 0.2588235437870026f, 1.0f);
	style.Colors[ImGuiCol_DragDropTarget] = ImVec4(1.0f, 1.0f, 0.0f, 0.8999999761581421f);
	style.Colors[ImGuiCol_NavHighlight] = ImVec4(0.0f, 0.0f, 0.0f, 0.6437768340110779f);
	style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.0f, 1.0f, 1.0f, 0.4678111672401428f);
	style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.733905553817749f);
	style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.7982832789421082f);

	//Applying The Custom Font To The ImGui
	ImFontConfig font;
	io.Fonts->AddFontFromMemoryTTF((void*)rawData, sizeof(rawData), 18.5f, &font);
}




//once again Basic Shit code But needed :)
LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}





//Here again Shit Code But Needed
bool init = false;
HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (!init)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)& pDevice)))
		{
			pDevice->GetImmediateContext(&pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow;
			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)& pBackBuffer);
			pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
			pBackBuffer->Release();
			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			InitImGui();
			init = true;
		}

		else
			return oPresent(pSwapChain, SyncInterval, Flags);
	}




	//Toggling The Menu Showing
	//These Keys Will Be Make The Menu Appear 
	//Im Going To add 2 Buttons TO open The menu


	//toggle hotkey "Delete" On The Keyboard
	if (GetAsyncKeyState(VK_DELETE) & 1) {
		globals::show = !globals::show;
	}

	//toggle hotkey "Delete" On The Keyboard
	if (GetAsyncKeyState(VK_INSERT) & 1) {
		globals::show = !globals::show;
	}




	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();



	//Watermark 

	
	//So Im Going To import a Real Time Clock For The Watermark
	auto start = std::chrono::system_clock::now();
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);



	// Were Now Going To Start Making A Watermark In The Left Top Corner
	// PLEASE NOTE:
	// U PROBABLY NEED TO ADJUST IT TO UR IMGUI SO IT FITS THE STYLE
	ImGui::SetNextWindowPos({ 15, 15 });
	ImGui::SetNextWindowSize({ 330,40 });
	ImGui::Begin("watermark", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar);
	ImGui::Text("CheatName | Dev | %s", std::ctime(&end_time));  //ALSO IF THIS DOESNT WORK FOR YOU AND GIVING U ERRORS GO TO UR SETTINGS AND PUT "_CRT_SECURE_NO_WARNINGS" WE DONT EVEN KNOW ON WHY IT FLAGS BUT YEA LOL 
	ImGui::End();


	//-----------Cl4vr´s Code ENDS HERE-----------













	//-----------oxyxiy´s Code-----------


	//Starting The Main Gui Of Your Cheat 

	if (globals::show)
	{ 
		ImGui::SetNextWindowSize(ImVec2(900, 450));
		ImGui::Begin(("ImGui Dll Base Written By Cl4vr & oxyxiy"), NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
		{
			//here are going to be the different Tabs
			//We are Only Going To do 2 Tho
			
			//main Category
			ImGui::SameLine(); 
			if (ImGui::Button(("Main"), ImVec2(410, 30)))
			{
				globals::tab = 0;
			}


			//misc Category
			ImGui::SameLine();
			if (ImGui::Button(("Misc"), ImVec2(410, 30)))
			{
				globals::tab = 1;
			}
		}


		ImGui::Separator();

		//Main Section & functions

		if (globals::tab == 0)
		{






			//-----------CHECKBOX-----------
			// 

			
			if (ImGui::Checkbox(("Checkbox"), &globals::checkbox1));
			{
				functions::Checkbox1();
			}

			//Now were going to do a Tool Tip This IS OPTIONAL Not Needed So This Explains What The Checkbox Is Going To Do 
			//Example When Hovered u can See Whats Writen In The ToolTip

			if (ImGui::Checkbox(("Checkbox With ToolTip"), &globals::checkbox2));
			{
				functions::Checkbox2();
			}

			if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
			{
				ImGui::SetTooltip("This Hover Effect Is The Tool Tip Created On Line 247 :)");
			}

			//-----------Checkbox End-----------














			//-----------Slider-----------
			//Now We are Going To make A SliderFLOAT For FOV Functions

 
			if (ImGui::SliderFloat(("SliderFloat"), &globals::Slider1, 0, 999))
			{
				functions::Slider();
			}


			//Now were going to do a ToolTip Once Again This IS OPTIONAL Not Needed So This Explains What The Slider Is Going To Do 
			//Example When Hovered u can See Whats Writen In The ToolTip

			if (ImGui::SliderFloat(("SliderFloat With ToolTip"), &globals::Slider2, 0, 999))
			{
				functions::Slider2();
			}

			if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
			{
				ImGui::SetTooltip("This Hover Effect Is The Tool Tip Created On Line 287 :)");
			}

			//-----------Slider End-----------


















			//-----------Buttons-----------

			if (ImGui::Button("Button"), &globals::button1)
			{
				functions::Button();
			}

			//Now were going to do a ToolTip Once Again This IS OPTIONAL Not Needed So This Explains What The Button Is Going To Do 
			//Example When Hovered u can See Whats Writen In The ToolTip

			if (ImGui::Button("Button With ToolTip"), &globals::button2)
			{
				functions::Button2();
			}


			if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
			{
				ImGui::SetTooltip("This Hover Effect Is The Tool Tip Created On Line 313 :)");
			}

			//-----------Buttons End-----------


















			//You can Also Add Text Usign A Separator Not Being That Ugly :)

			ImGui::Separator();
			ImGui::Text("This is An optional Text at Line 322 This does NOT need to Be implemented ");
			ImGui::Text("Writen With Love By Cl4vr & oxyxiy <3");

		}

		//now we Are Going To Make The second Tab Called "misc"

		if (globals::tab == 1)
		{
			ImGui::Separator(); //separator for The Style of it ;)

			//This is Going To Be a Uninject Button 
			//now this will not allow you To Rebuild Ur Project
			//Only Allows A User To Reinject

			if (ImGui::Button("Uninject"))
			{
				kiero::shutdown();
			}

			if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
			{
				ImGui::SetTooltip("Uninjects From The Game And Allows reinjection");
			}
			//This Time I Will Include A ToolTip U can Comment It out using the 2 at the start of every sentence

			//you can Also Add a Separator For It To Make Clean
			
			ImGui::Separator();


			//Linking Targets 
			if (ImGui::Button("oxyxiys Discord Server", ImVec2{ 215, 30 }))
			{
				ShellExecute(NULL, "open", "https://discord.gg/ceJetY6uY9", 0, 0, SW_SHOWNORMAL); //change the discord URL to ur own
			}

			if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
			{
				ImGui::SetTooltip("Opens The Discord Server Link In Your Browser");
			}
			//Once again with the tool tip


			//now the same with Youtube. Mind you can Put ANY url In These Lines

			if (ImGui::Button("Cl4vrs Youtube Channel", ImVec2{ 215, 30 }))
			{
				ShellExecute(NULL, "open", "https://youtube.com/@2behindert", 0, 0, SW_SHOWNORMAL);   // Change the Url To Any URL u Like :)
			}

			if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
			{
				ImGui::SetTooltip("Opens The Youtube URL or The URL Linked To The Code");
			}

			//So This is Basically The Whole Code We Are Going To Be Sharing :)





		}
		ImGui::End();

		
	}
	ImGui::Render();
	pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return oPresent(pSwapChain, SyncInterval, Flags);

	//basic render code

}



//-----------oxyxiy´s Code´ENDS HERE-----------




//Normal Dll Shit No Explaining Aswell
DWORD WINAPI MainThread(LPVOID lpReserved)
{
	bool init_hook = false;
	do
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			kiero::bind(8, (void**)& oPresent, hkPresent);
			init_hook = true;
		}
	} while (!init_hook);
	return TRUE;
}
//If THis Needs Explaining Then U Need Help.
BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hMod);
		CreateThread(nullptr, 0, MainThread, hMod, 0, nullptr);
		break;
	case DLL_PROCESS_DETACH:
		kiero::shutdown();
		break;
	}
	return TRUE;
}